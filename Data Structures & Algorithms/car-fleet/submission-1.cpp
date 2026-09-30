class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        std::vector<std::pair<int, int>> cars(n);

        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double fleetTime = 0.0;

        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            if (time > fleetTime) {
                ++fleets;
                fleetTime = time;
            }
        }

        return fleets;
    }
};
