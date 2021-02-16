# Gemcutter-Project-Template
A template repository for new projects using the [Gemcutter game framework](https://github.com/EmilianC/Gemcutter).

# Quick Start
Click "Use this template" above to duplicate the repository into your own account. Then clone the new project and make sure to also pull the Gemcutter submodule:
```
> git submodule init
> git submodule update
```
Gemcutter will initialize what it needs, so there is no need to pull submodules recursively.

You'll need to use CMake in order to generate the project files and build your game. Make sure to make a `build/` folder in the root directory for all outputs:
```
> mkdir build
> cd build
> cmake .. -DGAME_PROJECT_NAME=MyGame    # Configure the project with the name of your game
```
And that's it! You'll find your generated projects under the `build/` folder.