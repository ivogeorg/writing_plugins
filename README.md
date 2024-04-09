### writing_plugins

Exercise in writing Gazebo plugins, the brains behind simulated robot behavior :)

### Notes

1. Create plugin catkin package with the following requirements:
   ```
   catkin_create_pkg writing_plugins gazebo gazebo_ros gazebo_plugins roscpp
   ```  
2. After compilation, add the path to the plugin library (in this case `~/catkin_ws/devel/lib`) to the Gazebo plugin path:
   ```
   export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/catkin_ws/devel/lib
   ```  
3. Resetting the Gazebo simulation time does not reset any counter in the plugin code.

### References

1. Gazebo API [`SetLinearVel()`](https://osrf-distributions.s3.amazonaws.com/gazebo/api/dev/classgazebo_1_1physics_1_1Model.html#afbeccc662db81edbeba85992564442b7).
2. [Gazebo API Reference](https://osrf-distributions.s3.amazonaws.com/gazebo/api/dev/index.html).
3. Gazebo [Model Class Reference](https://osrf-distributions.s3.amazonaws.com/gazebo/api/dev/classgazebo_1_1physics_1_1Model.html).
4. SDF Format [Custom elements and attributes](http://sdformat.org/tutorials?tut=custom_elements_attributes_proposal).



