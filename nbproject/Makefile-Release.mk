#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/demo/Asteroid.o \
	${OBJECTDIR}/demo/CustomScript.o \
	${OBJECTDIR}/demo/JetParticle.o \
	${OBJECTDIR}/demo/MyGame.o \
	${OBJECTDIR}/demo/Starship.o \
	${OBJECTDIR}/demo/mainScene.o \
	${OBJECTDIR}/demo/particleDecay.o \
	${OBJECTDIR}/demo/scriptDePrueba.o \
	${OBJECTDIR}/engine/Component.o \
	${OBJECTDIR}/engine/GUI.o \
	${OBJECTDIR}/engine/Game.o \
	${OBJECTDIR}/engine/GameObject.o \
	${OBJECTDIR}/engine/Scene.o \
	${OBJECTDIR}/engine/components/BoxCollider.o \
	${OBJECTDIR}/engine/components/CircleCollider.o \
	${OBJECTDIR}/engine/components/Collider.o \
	${OBJECTDIR}/engine/components/MusicPlayer.o \
	${OBJECTDIR}/engine/components/Renderer.o \
	${OBJECTDIR}/engine/components/RigidBody.o \
	${OBJECTDIR}/engine/components/Script.o \
	${OBJECTDIR}/engine/components/SoundPlayer.o \
	${OBJECTDIR}/engine/components/Transform.o \
	${OBJECTDIR}/engine/facade/Clock.o \
	${OBJECTDIR}/engine/facade/Keyboard.o \
	${OBJECTDIR}/engine/facade/Mouse.o \
	${OBJECTDIR}/engine/facade/Music.o \
	${OBJECTDIR}/engine/facade/Sound.o \
	${OBJECTDIR}/engine/facade/Texture.o \
	${OBJECTDIR}/engine/facade/Time.o \
	${OBJECTDIR}/engine/facade/Vector2.o \
	${OBJECTDIR}/engine/facade/Window.o \
	${OBJECTDIR}/engine/gameobjects/Camera.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/source/IAMovement.o \
	${OBJECTDIR}/source/LifeManager.o \
	${OBJECTDIR}/source/PlayerMovement.o \
	${OBJECTDIR}/source/enemy.o \
	${OBJECTDIR}/source/generaPosicion.o \
	${OBJECTDIR}/source/imagenFondo.o \
	${OBJECTDIR}/source/mainGame.o \
	${OBJECTDIR}/source/moveFondo.o \
	${OBJECTDIR}/source/player.o \
	${OBJECTDIR}/source/sceneMenu.o \
	${OBJECTDIR}/source/scenePrueba.o \
	${OBJECTDIR}/source/sceneSplash.o \
	${OBJECTDIR}/source/splash.o \
	${OBJECTDIR}/source/staticObject.o \
	${OBJECTDIR}/source/voidObject.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Llibs/SFML-2.1/lib -Llibs/Box2D/lib -Llibs/json-c/.libs -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lBox2D -ljson-c

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/demo/Asteroid.o: demo/Asteroid.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/Asteroid.o demo/Asteroid.cpp

${OBJECTDIR}/demo/CustomScript.o: demo/CustomScript.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/CustomScript.o demo/CustomScript.cpp

${OBJECTDIR}/demo/JetParticle.o: demo/JetParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/JetParticle.o demo/JetParticle.cpp

${OBJECTDIR}/demo/MyGame.o: demo/MyGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/MyGame.o demo/MyGame.cpp

${OBJECTDIR}/demo/Starship.o: demo/Starship.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/Starship.o demo/Starship.cpp

${OBJECTDIR}/demo/mainScene.o: demo/mainScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/mainScene.o demo/mainScene.cpp

${OBJECTDIR}/demo/particleDecay.o: demo/particleDecay.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/particleDecay.o demo/particleDecay.cpp

${OBJECTDIR}/demo/scriptDePrueba.o: demo/scriptDePrueba.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/scriptDePrueba.o demo/scriptDePrueba.cpp

${OBJECTDIR}/engine/Component.o: engine/Component.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Component.o engine/Component.cpp

${OBJECTDIR}/engine/GUI.o: engine/GUI.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/GUI.o engine/GUI.cpp

${OBJECTDIR}/engine/Game.o: engine/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Game.o engine/Game.cpp

${OBJECTDIR}/engine/GameObject.o: engine/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/GameObject.o engine/GameObject.cpp

${OBJECTDIR}/engine/Scene.o: engine/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Scene.o engine/Scene.cpp

${OBJECTDIR}/engine/components/BoxCollider.o: engine/components/BoxCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/BoxCollider.o engine/components/BoxCollider.cpp

${OBJECTDIR}/engine/components/CircleCollider.o: engine/components/CircleCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/CircleCollider.o engine/components/CircleCollider.cpp

${OBJECTDIR}/engine/components/Collider.o: engine/components/Collider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Collider.o engine/components/Collider.cpp

${OBJECTDIR}/engine/components/MusicPlayer.o: engine/components/MusicPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/MusicPlayer.o engine/components/MusicPlayer.cpp

${OBJECTDIR}/engine/components/Renderer.o: engine/components/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Renderer.o engine/components/Renderer.cpp

${OBJECTDIR}/engine/components/RigidBody.o: engine/components/RigidBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/RigidBody.o engine/components/RigidBody.cpp

${OBJECTDIR}/engine/components/Script.o: engine/components/Script.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Script.o engine/components/Script.cpp

${OBJECTDIR}/engine/components/SoundPlayer.o: engine/components/SoundPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/SoundPlayer.o engine/components/SoundPlayer.cpp

${OBJECTDIR}/engine/components/Transform.o: engine/components/Transform.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Transform.o engine/components/Transform.cpp

${OBJECTDIR}/engine/facade/Clock.o: engine/facade/Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Clock.o engine/facade/Clock.cpp

${OBJECTDIR}/engine/facade/Keyboard.o: engine/facade/Keyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Keyboard.o engine/facade/Keyboard.cpp

${OBJECTDIR}/engine/facade/Mouse.o: engine/facade/Mouse.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Mouse.o engine/facade/Mouse.cpp

${OBJECTDIR}/engine/facade/Music.o: engine/facade/Music.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Music.o engine/facade/Music.cpp

${OBJECTDIR}/engine/facade/Sound.o: engine/facade/Sound.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Sound.o engine/facade/Sound.cpp

${OBJECTDIR}/engine/facade/Texture.o: engine/facade/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Texture.o engine/facade/Texture.cpp

${OBJECTDIR}/engine/facade/Time.o: engine/facade/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Time.o engine/facade/Time.cpp

${OBJECTDIR}/engine/facade/Vector2.o: engine/facade/Vector2.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Vector2.o engine/facade/Vector2.cpp

${OBJECTDIR}/engine/facade/Window.o: engine/facade/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Window.o engine/facade/Window.cpp

${OBJECTDIR}/engine/gameobjects/Camera.o: engine/gameobjects/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/gameobjects
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/gameobjects/Camera.o engine/gameobjects/Camera.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/source/IAMovement.o: source/IAMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IAMovement.o source/IAMovement.cpp

${OBJECTDIR}/source/LifeManager.o: source/LifeManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LifeManager.o source/LifeManager.cpp

${OBJECTDIR}/source/PlayerMovement.o: source/PlayerMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/PlayerMovement.o source/PlayerMovement.cpp

${OBJECTDIR}/source/enemy.o: source/enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/enemy.o source/enemy.cpp

${OBJECTDIR}/source/generaPosicion.o: source/generaPosicion.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/generaPosicion.o source/generaPosicion.cpp

${OBJECTDIR}/source/imagenFondo.o: source/imagenFondo.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/imagenFondo.o source/imagenFondo.cpp

${OBJECTDIR}/source/mainGame.o: source/mainGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/mainGame.o source/mainGame.cpp

${OBJECTDIR}/source/moveFondo.o: source/moveFondo.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/moveFondo.o source/moveFondo.cpp

${OBJECTDIR}/source/player.o: source/player.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/player.o source/player.cpp

${OBJECTDIR}/source/sceneMenu.o: source/sceneMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/sceneMenu.o source/sceneMenu.cpp

${OBJECTDIR}/source/scenePrueba.o: source/scenePrueba.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/scenePrueba.o source/scenePrueba.cpp

${OBJECTDIR}/source/sceneSplash.o: source/sceneSplash.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/sceneSplash.o source/sceneSplash.cpp

${OBJECTDIR}/source/splash.o: source/splash.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/splash.o source/splash.cpp

${OBJECTDIR}/source/staticObject.o: source/staticObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/staticObject.o source/staticObject.cpp

${OBJECTDIR}/source/voidObject.o: source/voidObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/voidObject.o source/voidObject.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
