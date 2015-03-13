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
CND_CONF=Debug
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
	${OBJECTDIR}/hito1/BackgroundParallax.o \
	${OBJECTDIR}/hito1/CameraFollowPlayer.o \
	${OBJECTDIR}/hito1/MakeMapFromFile.o \
	${OBJECTDIR}/hito1/PlayerMovement.o \
	${OBJECTDIR}/hito1/TileRowGenerator.o \
	${OBJECTDIR}/hito1/backgroundLayer.o \
	${OBJECTDIR}/hito1/generaPosicion.o \
	${OBJECTDIR}/hito1/hito1Game.o \
	${OBJECTDIR}/hito1/limit.o \
	${OBJECTDIR}/hito1/player.o \
	${OBJECTDIR}/hito1/pruebaGameObject.o \
	${OBJECTDIR}/hito1/scene51.o \
	${OBJECTDIR}/hito1/sceneEntregable3.o \
	${OBJECTDIR}/hito1/sceneEntregable4.o \
	${OBJECTDIR}/hito1/tile.o \
	${OBJECTDIR}/hito1/tileMapGenerator.o \
	${OBJECTDIR}/hito1/tileRow.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-Llibs/SFML-2.1/lib -Llibs/Box2D/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lBox2D

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/demo/Asteroid.o: demo/Asteroid.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/Asteroid.o demo/Asteroid.cpp

${OBJECTDIR}/demo/CustomScript.o: demo/CustomScript.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/CustomScript.o demo/CustomScript.cpp

${OBJECTDIR}/demo/JetParticle.o: demo/JetParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/JetParticle.o demo/JetParticle.cpp

${OBJECTDIR}/demo/MyGame.o: demo/MyGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/MyGame.o demo/MyGame.cpp

${OBJECTDIR}/demo/Starship.o: demo/Starship.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/Starship.o demo/Starship.cpp

${OBJECTDIR}/demo/mainScene.o: demo/mainScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/mainScene.o demo/mainScene.cpp

${OBJECTDIR}/demo/particleDecay.o: demo/particleDecay.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/particleDecay.o demo/particleDecay.cpp

${OBJECTDIR}/demo/scriptDePrueba.o: demo/scriptDePrueba.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/scriptDePrueba.o demo/scriptDePrueba.cpp

${OBJECTDIR}/engine/Component.o: engine/Component.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Component.o engine/Component.cpp

${OBJECTDIR}/engine/Game.o: engine/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Game.o engine/Game.cpp

${OBJECTDIR}/engine/GameObject.o: engine/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/GameObject.o engine/GameObject.cpp

${OBJECTDIR}/engine/Scene.o: engine/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Scene.o engine/Scene.cpp

${OBJECTDIR}/engine/components/BoxCollider.o: engine/components/BoxCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/BoxCollider.o engine/components/BoxCollider.cpp

${OBJECTDIR}/engine/components/CircleCollider.o: engine/components/CircleCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/CircleCollider.o engine/components/CircleCollider.cpp

${OBJECTDIR}/engine/components/Collider.o: engine/components/Collider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Collider.o engine/components/Collider.cpp

${OBJECTDIR}/engine/components/MusicPlayer.o: engine/components/MusicPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/MusicPlayer.o engine/components/MusicPlayer.cpp

${OBJECTDIR}/engine/components/Renderer.o: engine/components/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Renderer.o engine/components/Renderer.cpp

${OBJECTDIR}/engine/components/RigidBody.o: engine/components/RigidBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/RigidBody.o engine/components/RigidBody.cpp

${OBJECTDIR}/engine/components/Script.o: engine/components/Script.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Script.o engine/components/Script.cpp

${OBJECTDIR}/engine/components/SoundPlayer.o: engine/components/SoundPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/SoundPlayer.o engine/components/SoundPlayer.cpp

${OBJECTDIR}/engine/components/Transform.o: engine/components/Transform.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Transform.o engine/components/Transform.cpp

${OBJECTDIR}/engine/facade/Clock.o: engine/facade/Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Clock.o engine/facade/Clock.cpp

${OBJECTDIR}/engine/facade/Keyboard.o: engine/facade/Keyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Keyboard.o engine/facade/Keyboard.cpp

${OBJECTDIR}/engine/facade/Mouse.o: engine/facade/Mouse.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Mouse.o engine/facade/Mouse.cpp

${OBJECTDIR}/engine/facade/Music.o: engine/facade/Music.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Music.o engine/facade/Music.cpp

${OBJECTDIR}/engine/facade/Sound.o: engine/facade/Sound.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Sound.o engine/facade/Sound.cpp

${OBJECTDIR}/engine/facade/Texture.o: engine/facade/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Texture.o engine/facade/Texture.cpp

${OBJECTDIR}/engine/facade/Time.o: engine/facade/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Time.o engine/facade/Time.cpp

${OBJECTDIR}/engine/facade/Vector2.o: engine/facade/Vector2.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Vector2.o engine/facade/Vector2.cpp

${OBJECTDIR}/engine/facade/Window.o: engine/facade/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Window.o engine/facade/Window.cpp

${OBJECTDIR}/engine/gameobjects/Camera.o: engine/gameobjects/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/gameobjects
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/gameobjects/Camera.o engine/gameobjects/Camera.cpp

${OBJECTDIR}/hito1/BackgroundParallax.o: hito1/BackgroundParallax.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/BackgroundParallax.o hito1/BackgroundParallax.cpp

${OBJECTDIR}/hito1/CameraFollowPlayer.o: hito1/CameraFollowPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/CameraFollowPlayer.o hito1/CameraFollowPlayer.cpp

${OBJECTDIR}/hito1/MakeMapFromFile.o: hito1/MakeMapFromFile.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/MakeMapFromFile.o hito1/MakeMapFromFile.cpp

${OBJECTDIR}/hito1/PlayerMovement.o: hito1/PlayerMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/PlayerMovement.o hito1/PlayerMovement.cpp

${OBJECTDIR}/hito1/TileRowGenerator.o: hito1/TileRowGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/TileRowGenerator.o hito1/TileRowGenerator.cpp

${OBJECTDIR}/hito1/backgroundLayer.o: hito1/backgroundLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/backgroundLayer.o hito1/backgroundLayer.cpp

${OBJECTDIR}/hito1/generaPosicion.o: hito1/generaPosicion.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/generaPosicion.o hito1/generaPosicion.cpp

${OBJECTDIR}/hito1/hito1Game.o: hito1/hito1Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/hito1Game.o hito1/hito1Game.cpp

${OBJECTDIR}/hito1/limit.o: hito1/limit.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/limit.o hito1/limit.cpp

${OBJECTDIR}/hito1/player.o: hito1/player.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/player.o hito1/player.cpp

${OBJECTDIR}/hito1/pruebaGameObject.o: hito1/pruebaGameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/pruebaGameObject.o hito1/pruebaGameObject.cpp

${OBJECTDIR}/hito1/scene51.o: hito1/scene51.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/scene51.o hito1/scene51.cpp

${OBJECTDIR}/hito1/sceneEntregable3.o: hito1/sceneEntregable3.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/sceneEntregable3.o hito1/sceneEntregable3.cpp

${OBJECTDIR}/hito1/sceneEntregable4.o: hito1/sceneEntregable4.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/sceneEntregable4.o hito1/sceneEntregable4.cpp

${OBJECTDIR}/hito1/tile.o: hito1/tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/tile.o hito1/tile.cpp

${OBJECTDIR}/hito1/tileMapGenerator.o: hito1/tileMapGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/tileMapGenerator.o hito1/tileMapGenerator.cpp

${OBJECTDIR}/hito1/tileRow.o: hito1/tileRow.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/tileRow.o hito1/tileRow.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
