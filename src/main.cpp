#include <bits/stdc++.h>
#include "load_files.h"
#include "spread.h"

using std::vector;
using graph::City;

void printUsage(std::string command) {
  std::cout << "Usage: " << command << " START_POINT LATENCY_PERIOD \n";
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return 1;
    }

    auto g = csv_to_graph();

    Spread instance(*g, argv[1], std::stoi(argv[2]));

    ofstream ofs_status("../bin/status.csv");
    ofstream ofs_node("../bin/nodes.csv");

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

        cnt = 0;

        auto status = instance.getStatus();

        for (const auto& it : status) {
            ofs_status << it.second << (it == *(--status.end())? '\n' : '|');

            if (it.second == "I") cnt++;
        }
    }

    ofs_node.close();
}