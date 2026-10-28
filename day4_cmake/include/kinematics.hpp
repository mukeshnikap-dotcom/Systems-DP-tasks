#ifndef KINEMATICS_HPP
#define KINEMATICS_HPP

namespace kinematics {

struct State {
    double x{0.0};
    double y{0.0};
    double theta{0.0}; // Heading in radians
};

class AckermannModel {
public:
    // Explicit constructor to prevent implicit conversions
    explicit AckermannModel(double wheelbase);

    // Computes the next state using kinematic bicycle model equations
    [[nodiscard]] State update(const State& current_state, double velocity, double steering_angle, double dt) const;

private:
    double wheelbase_;
};

} // namespace kinematics

#endif // KINEMATICS_HPP
