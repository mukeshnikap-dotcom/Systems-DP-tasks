#include "kinematics.hpp"
#include <iostream>
#include <iomanip>

int main() {
    // Initialize a model with a 2.5 meter wheelbase
    kinematics::AckermannModel vehicle(2.5);

    // Initial state: centered at origin, pointing straight along the X-axis
    kinematics::State state{0.0, 0.0, 0.0};

    double velocity = 5.0;         // 5 m/s
    double steering_angle = 0.2;    // ~11.4 degrees
    double dt = 0.1;               // 100ms time step

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Starting Simulation (10 steps):\n";
    std::cout << "Step |   X    |   Y    |  Theta \n";
    std::cout << "---------------------------------\n";

    for (int i = 0; i < 10; ++i) {
        state = vehicle.update(state, velocity, steering_angle, dt);
        std::cout << std::setw(4) << i + 1 << " | "
                  << std::setw(6) << state.x << " | "
                  << std::setw(6) << state.y << " | "
                  << std::setw(6) << state.theta << "\n";
    }

    return 0;
}
