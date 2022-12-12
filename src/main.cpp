#include <bits/stdc++.h>
#include "load_files.h"
#include "spread.h"

using std::vector;
using graph::City;

const auto output_node_path = "../bin/nodes.csv";
const auto output_status_path = "../bin/status.csv";

void printUsage(std::string command) {
  std::cout << "Usage: " << command << " START_POINT LATENCY_PERIOD [BLOCK_TIME BLOCK_1 BLOCK_2 ... ] \n";
}

int main(int argc, char* argv[]) {
    if (argc != 3 && argc < 5) {
        printUsage(argv[0]);
        return 1;
    }

    auto g = csv_to_graph();

    Spread instance(*g, argv[1], std::stoi(argv[2]));

    ofstream ofs_status(output_status_path);
    ofstream ofs_node(output_node_path);

    ofs_node << "Name,State,Latitude,Longitude\n";

    auto status = instance.getStatus();
    for (const auto& v : status) {
        auto c = static_cast<City*>(v.first);
        ofs_node << c->getName() << ',' << c->getLatitude() << ',' << c->getLongitude() << '\n';
        ofs_status << c->getName() << (v == *(--status.end())? '\n' : '|');
    }

    ofs_node.close();

    size_t cnt = 0;

    while (cnt != g->getVertexList().size() && instance.getTimeStamp() <= 300) {
        instance.nextStep();

        if (argc >= 5 && stoul(argv[3]) == instance.getTimeStamp()) {
            vector<string> v;

            for (int i = 4; i < argc; i++)
                v.push_back(argv[i]);

            instance.isolate(v);
        }

        cnt = 0;

        auto status = instance.getStatus();

        for (const auto& it : status) {
            ofs_status << it.second << (it == *(--status.end())? '\n' : '|');

            if (it.second == "I") cnt++;
        }
    }

    ofs_node.close();
}