#include <bits/stdc++.h>
#include "load_files.h"
#include "spread.h"

using std::vector;
using graph::City;

int main() {
    auto g = csv_to_graph();

    auto virus = Spread(*g, static_cast<City*>(g->getVertex("Los Angeles, CA")), 3);

    for (int _ = 0; _ < 10; _++) {
        virus.nextStep();
    }

    virus.isolate({"Washington, DC", "Syracuse, NY"});

    virus.intersect();

    virus.getTimeStamp();
    virus.getCost();
}