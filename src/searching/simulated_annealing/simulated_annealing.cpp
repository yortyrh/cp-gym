#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
};
static FastIO fastio;

signed main() {
    double start, target;
    cin >> start >> target;
    auto energy = [&](double x) {
        double delta = x - target;
        return delta * delta;
    };
    mt19937 rng(1);
    uniform_real_distribution<double> unit(0.0, 1.0);
    uniform_real_distribution<double> step(-1.0, 1.0);
    int steps = 2000;
    double current = start;
    double current_energy = energy(current);
    double best = current;
    double best_energy = current_energy;
    for (int index = 0; index < steps; ++index) {
        double temperature = 1.0 - static_cast<double>(index) / static_cast<double>(steps);
        double candidate = current + step(rng) * (0.1 + temperature);
        double candidate_energy = energy(candidate);
        double delta = candidate_energy - current_energy;
        if (delta <= 0.0 || unit(rng) < exp(-delta / max(temperature, 1e-12))) {
            current = candidate;
            current_energy = candidate_energy;
            if (current_energy < best_energy) {
                best = current;
                best_energy = current_energy;
            }
        }
    }
    cout << fixed << setprecision(10) << best << '\n';
    return 0;
}
