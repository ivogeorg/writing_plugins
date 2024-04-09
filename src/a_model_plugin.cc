#include <functional>
#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo {
class AModelPlugin : public ModelPlugin {
public:
  void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf) {
    // Store the pointer to the model
    this->model = _parent;

    // NOTENOTE >> This code crashes Gazebo!?!?!?
    // Get world parameters
    // if (_sdf->HasElement("iterations")) {
    //   this->iterations = _sdf->Get<int>("iterations");
    // }
    // if (_sdf->HasElement("side_iter")) {
    //   this->side_iter = _sdf->Get<int>("side_iter");
    // }
    // if (_sdf->HasElement("linear_vel")) {
    //   this->iterations = _sdf->Get<double>("linear_vel");
    // }
    // NOTENOTE << End.

    // // DEBUGDEBUG
    // std::cout << "iterations = " << this->iterations << '\n';
    // std::cout << "side_iter = " << this->side_iter << '\n';
    // std::cout << "linear_vel = " << this->linear_vel << '\n';

    // >> their code doesn't
    std::cout << "Load before params"
              << "\n";

    this->linear_vel = 0.1;
    if (_sdf->HasElement("linear_vel")) {
      this->linear_vel = _sdf->Get<double>("linear_vel");
    }
    std::cout << "linear_vel = " << this->linear_vel << "\n";

    this->iterations = 10 * 1000;
    if (_sdf->HasElement("iterations")) {
      this->iterations = _sdf->Get<int>("iterations");
    }
    std::cout << "iterations = " << this->iterations << "\n";

    this->side_iter = 3000;
    if (_sdf->HasElement("side_iter")) {
      this->side_iter = _sdf->Get<int>("side_iter");
    }
    std::cout << "side_iter = " << this->side_iter << "\n";

    std::cout << "Load after params"
              << "\n";
    // << their code

    // Listen to the update event. This event is broadcast every
    // simulation iteration.
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(
        std::bind(&AModelPlugin::OnUpdate, this));
  }

  // Called by the world update start event
public:
  void OnUpdate() {
    // Apply a small linear velocity to the model.

    if (this->counter < this->iterations) {

      this->model->SetLinearVel(
          ignition::math::Vector3d(dir[dir_ix].first * this->linear_vel,
                                   dir[dir_ix].second * this->linear_vel, 0));
      //   this->model->SetLinearAccel(ignition::math::Vector3d(0, 0, 0));
    }

    this->counter++;
    if (this->counter % this->iterations == 0) {
      this->counter = 0;
    }
    if (this->counter % this->side_iter == 0) {
      this->dir_ix = (this->dir_ix + 1) % 4;
    }
  }

  // Pointer to the model
private:
  physics::ModelPtr model;

private:
  int counter = 0;
  int iterations = 15000;
  double linear_vel = 0.2;
  int dir_ix = 0;
  const std::array<std::pair<int, int>, 4> dir = {
      {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
  int side_iter = 3000;

  // Pointer to the update event connection
private:
  event::ConnectionPtr updateConnection;
};

// Register this plugin with the simulator
GZ_REGISTER_MODEL_PLUGIN(AModelPlugin)
} // namespace gazebo