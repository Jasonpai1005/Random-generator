#include <iostream>
#include "net_config.h"
#include "layout.h"

int main(){
    std::vector<std::pair<int, Net_config>> net_configs;
    int test_num = 1;
    for(int i = 0; i < test_num; ++i){
        net_configs.clear();
        Layout L(20, 20, 3, i); // (width, height, layer, case numbers)
        // L.generateObstacles({24,24,24,24,24,24}, {{3,10},{3,10},{3,10},{3,10},{3,10},{3,10}});
        L.generateObstacles({4,4,4}, {{3,5},{3,5},{3,5}}); // (obs numbers per layer, obs size range)
        //Net_config net_2_pins(10, 35, 60, 2, 20, 0.85);
        L.autoConfig(net_configs);
        L.generateNets(net_configs);
        //L.generateNets({{200, net_2_pins}});
#ifdef DEBUG
        // L.checkLegal();
#endif
        std::string file_name = "id_" + std::to_string(i) + ".txt";
        L.saveResult(file_name);
        //L.archiveAndReset();
        std::cout << std::endl;
    }
    return 0;
}