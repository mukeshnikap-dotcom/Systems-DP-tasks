#include "kinematics.hpp"
#include <cmath>

namespace kinematics {

AckermannModel::AckermannModel(double wheelbase) : wheelbase_(wheelbase) {}

State AckermannModel::update(const State& current_state, double velocity, double steering_angle, double dt) const {
    State next_state = current_state;

    // Avoid division by zero if wheelbase is invalid or tiny
    if (std::abs(wheelbase_) < 1e-6) {
        return next_state;
    }

    // Kinematic updates
    next_state.x += velocity * std::cos(current_state.theta) * dt;
    next_state.y += velocity * std::sin(current_state.theta) * dt;
    next_state.theta += (velocity / wheelbase_) * std::tan(steering_angle) * dt;

    // Normalize theta to [-pi, pi]
    next_state.theta = std::atan2(std::sin(next_state.theta), std::cos(next_state.theta));

    return next_state;
}

} // namespace kinematics
