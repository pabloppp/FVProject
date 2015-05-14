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
	${OBJECTDIR}/source/Animator.o \
	${OBJECTDIR}/source/BackgroundParallax.o \
	${OBJECTDIR}/source/CameraFollowPlayer.o \
	${OBJECTDIR}/source/ColectableScript.o \
	${OBJECTDIR}/source/GameManager.o \
	${OBJECTDIR}/source/GlobalStateManager.o \
	${OBJECTDIR}/source/IABoss.o \
	${OBJECTDIR}/source/IAMovement.o \
	${OBJECTDIR}/source/IntroS1Manager.o \
	${OBJECTDIR}/source/LifeManager.o \
	${OBJECTDIR}/source/MainMenuSetup.o \
	${OBJECTDIR}/source/MenuManager.o \
	${OBJECTDIR}/source/PlayerMovement.o \
	${OBJECTDIR}/source/SaveManager.o \
	${OBJECTDIR}/source/TileRowGenerator.o \
	${OBJECTDIR}/source/backgroundLayer.o \
	${OBJECTDIR}/source/colectableGameObject.o \
	${OBJECTDIR}/source/defaultParticle.o \
	${OBJECTDIR}/source/emptyGameObject.o \
	${OBJECTDIR}/source/enemy.o \
	${OBJECTDIR}/source/enemy_boss.o \
	${OBJECTDIR}/source/enemy_fast.o \
	${OBJECTDIR}/source/escopetaBehavior.o \
	${OBJECTDIR}/source/escopetaBullet.o \
	${OBJECTDIR}/source/generaPosicion.o \
	${OBJECTDIR}/source/limit.o \
	${OBJECTDIR}/source/llamasBullet.o \
	${OBJECTDIR}/source/llbBehavior.o \
	${OBJECTDIR}/source/lnzllamasBehavior.o \
	${OBJECTDIR}/source/mainGame.o \
	${OBJECTDIR}/source/mapGenerator.o \
	${OBJECTDIR}/source/mbBehavior.o \
	${OBJECTDIR}/source/metralletaBehavior.o \
	${OBJECTDIR}/source/metralletaBullet.o \
	${OBJECTDIR}/source/moveClouds.o \
	${OBJECTDIR}/source/moveToTop.o \
	${OBJECTDIR}/source/myMenu.o \
	${OBJECTDIR}/source/oleada2.o \
	${OBJECTDIR}/source/pbBehavior.o \
	${OBJECTDIR}/source/pistolaBehavior.o \
	${OBJECTDIR}/source/pistolaBullet.o \
	${OBJECTDIR}/source/player.o \
	${OBJECTDIR}/source/sbBehavior.o \
	${OBJECTDIR}/source/sceneMenu.o \
	${OBJECTDIR}/source/sceneSplash.o \
	${OBJECTDIR}/source/splash.o \
	${OBJECTDIR}/source/sprayParticleScript.o \
	${OBJECTDIR}/source/staticObject.o \
	${OBJECTDIR}/source/tile.o \
	${OBJECTDIR}/source/tileDestroyManager.o \
	${OBJECTDIR}/source/tileRow.o \
	${OBJECTDIR}/source/tilerJsonLoadScene.o \
	${OBJECTDIR}/source/transitionScene.o \
	${OBJECTDIR}/source/weapon.o


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
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/Asteroid.o demo/Asteroid.cpp

${OBJECTDIR}/demo/CustomScript.o: demo/CustomScript.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/CustomScript.o demo/CustomScript.cpp

${OBJECTDIR}/demo/JetParticle.o: demo/JetParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/JetParticle.o demo/JetParticle.cpp

${OBJECTDIR}/demo/MyGame.o: demo/MyGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/MyGame.o demo/MyGame.cpp

${OBJECTDIR}/demo/Starship.o: demo/Starship.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/Starship.o demo/Starship.cpp

${OBJECTDIR}/demo/mainScene.o: demo/mainScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/mainScene.o demo/mainScene.cpp

${OBJECTDIR}/demo/particleDecay.o: demo/particleDecay.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/particleDecay.o demo/particleDecay.cpp

${OBJECTDIR}/demo/scriptDePrueba.o: demo/scriptDePrueba.cpp 
	${MKDIR} -p ${OBJECTDIR}/demo
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/demo/scriptDePrueba.o demo/scriptDePrueba.cpp

${OBJECTDIR}/engine/Component.o: engine/Component.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Component.o engine/Component.cpp

${OBJECTDIR}/engine/GUI.o: engine/GUI.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/GUI.o engine/GUI.cpp

${OBJECTDIR}/engine/Game.o: engine/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Game.o engine/Game.cpp

${OBJECTDIR}/engine/GameObject.o: engine/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/GameObject.o engine/GameObject.cpp

${OBJECTDIR}/engine/Scene.o: engine/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Scene.o engine/Scene.cpp

${OBJECTDIR}/engine/components/BoxCollider.o: engine/components/BoxCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/BoxCollider.o engine/components/BoxCollider.cpp

${OBJECTDIR}/engine/components/CircleCollider.o: engine/components/CircleCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/CircleCollider.o engine/components/CircleCollider.cpp

${OBJECTDIR}/engine/components/Collider.o: engine/components/Collider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Collider.o engine/components/Collider.cpp

${OBJECTDIR}/engine/components/MusicPlayer.o: engine/components/MusicPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/MusicPlayer.o engine/components/MusicPlayer.cpp

${OBJECTDIR}/engine/components/Renderer.o: engine/components/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Renderer.o engine/components/Renderer.cpp

${OBJECTDIR}/engine/components/RigidBody.o: engine/components/RigidBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/RigidBody.o engine/components/RigidBody.cpp

${OBJECTDIR}/engine/components/Script.o: engine/components/Script.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Script.o engine/components/Script.cpp

${OBJECTDIR}/engine/components/SoundPlayer.o: engine/components/SoundPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/SoundPlayer.o engine/components/SoundPlayer.cpp

${OBJECTDIR}/engine/components/Transform.o: engine/components/Transform.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Transform.o engine/components/Transform.cpp

${OBJECTDIR}/engine/facade/Clock.o: engine/facade/Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Clock.o engine/facade/Clock.cpp

${OBJECTDIR}/engine/facade/Keyboard.o: engine/facade/Keyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Keyboard.o engine/facade/Keyboard.cpp

${OBJECTDIR}/engine/facade/Mouse.o: engine/facade/Mouse.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Mouse.o engine/facade/Mouse.cpp

${OBJECTDIR}/engine/facade/Music.o: engine/facade/Music.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Music.o engine/facade/Music.cpp

${OBJECTDIR}/engine/facade/Sound.o: engine/facade/Sound.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Sound.o engine/facade/Sound.cpp

${OBJECTDIR}/engine/facade/Texture.o: engine/facade/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Texture.o engine/facade/Texture.cpp

${OBJECTDIR}/engine/facade/Time.o: engine/facade/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Time.o engine/facade/Time.cpp

${OBJECTDIR}/engine/facade/Vector2.o: engine/facade/Vector2.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Vector2.o engine/facade/Vector2.cpp

${OBJECTDIR}/engine/facade/Window.o: engine/facade/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Window.o engine/facade/Window.cpp

${OBJECTDIR}/engine/gameobjects/Camera.o: engine/gameobjects/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/gameobjects
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/gameobjects/Camera.o engine/gameobjects/Camera.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/source/Animator.o: source/Animator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Animator.o source/Animator.cpp

${OBJECTDIR}/source/BackgroundParallax.o: source/BackgroundParallax.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/BackgroundParallax.o source/BackgroundParallax.cpp

${OBJECTDIR}/source/CameraFollowPlayer.o: source/CameraFollowPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/CameraFollowPlayer.o source/CameraFollowPlayer.cpp

${OBJECTDIR}/source/ColectableScript.o: source/ColectableScript.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ColectableScript.o source/ColectableScript.cpp

${OBJECTDIR}/source/GameManager.o: source/GameManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/GameManager.o source/GameManager.cpp

${OBJECTDIR}/source/GlobalStateManager.o: source/GlobalStateManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/GlobalStateManager.o source/GlobalStateManager.cpp

${OBJECTDIR}/source/IABoss.o: source/IABoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IABoss.o source/IABoss.cpp

${OBJECTDIR}/source/IAMovement.o: source/IAMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IAMovement.o source/IAMovement.cpp

${OBJECTDIR}/source/IntroS1Manager.o: source/IntroS1Manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IntroS1Manager.o source/IntroS1Manager.cpp

${OBJECTDIR}/source/LifeManager.o: source/LifeManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LifeManager.o source/LifeManager.cpp

${OBJECTDIR}/source/MainMenuSetup.o: source/MainMenuSetup.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MainMenuSetup.o source/MainMenuSetup.cpp

${OBJECTDIR}/source/MenuManager.o: source/MenuManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MenuManager.o source/MenuManager.cpp

${OBJECTDIR}/source/PlayerMovement.o: source/PlayerMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/PlayerMovement.o source/PlayerMovement.cpp

${OBJECTDIR}/source/SaveManager.o: source/SaveManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SaveManager.o source/SaveManager.cpp

${OBJECTDIR}/source/TileRowGenerator.o: source/TileRowGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/TileRowGenerator.o source/TileRowGenerator.cpp

${OBJECTDIR}/source/backgroundLayer.o: source/backgroundLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/backgroundLayer.o source/backgroundLayer.cpp

${OBJECTDIR}/source/colectableGameObject.o: source/colectableGameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/colectableGameObject.o source/colectableGameObject.cpp

${OBJECTDIR}/source/defaultParticle.o: source/defaultParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/defaultParticle.o source/defaultParticle.cpp

${OBJECTDIR}/source/emptyGameObject.o: source/emptyGameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/emptyGameObject.o source/emptyGameObject.cpp

${OBJECTDIR}/source/enemy.o: source/enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/enemy.o source/enemy.cpp

${OBJECTDIR}/source/enemy_boss.o: source/enemy_boss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/enemy_boss.o source/enemy_boss.cpp

${OBJECTDIR}/source/enemy_fast.o: source/enemy_fast.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/enemy_fast.o source/enemy_fast.cpp

${OBJECTDIR}/source/escopetaBehavior.o: source/escopetaBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/escopetaBehavior.o source/escopetaBehavior.cpp

${OBJECTDIR}/source/escopetaBullet.o: source/escopetaBullet.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/escopetaBullet.o source/escopetaBullet.cpp

${OBJECTDIR}/source/generaPosicion.o: source/generaPosicion.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/generaPosicion.o source/generaPosicion.cpp

${OBJECTDIR}/source/limit.o: source/limit.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/limit.o source/limit.cpp

${OBJECTDIR}/source/llamasBullet.o: source/llamasBullet.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/llamasBullet.o source/llamasBullet.cpp

${OBJECTDIR}/source/llbBehavior.o: source/llbBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/llbBehavior.o source/llbBehavior.cpp

${OBJECTDIR}/source/lnzllamasBehavior.o: source/lnzllamasBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/lnzllamasBehavior.o source/lnzllamasBehavior.cpp

${OBJECTDIR}/source/mainGame.o: source/mainGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/mainGame.o source/mainGame.cpp

${OBJECTDIR}/source/mapGenerator.o: source/mapGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/mapGenerator.o source/mapGenerator.cpp

${OBJECTDIR}/source/mbBehavior.o: source/mbBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/mbBehavior.o source/mbBehavior.cpp

${OBJECTDIR}/source/metralletaBehavior.o: source/metralletaBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/metralletaBehavior.o source/metralletaBehavior.cpp

${OBJECTDIR}/source/metralletaBullet.o: source/metralletaBullet.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/metralletaBullet.o source/metralletaBullet.cpp

${OBJECTDIR}/source/moveClouds.o: source/moveClouds.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/moveClouds.o source/moveClouds.cpp

${OBJECTDIR}/source/moveToTop.o: source/moveToTop.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/moveToTop.o source/moveToTop.cpp

${OBJECTDIR}/source/myMenu.o: source/myMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/myMenu.o source/myMenu.cpp

${OBJECTDIR}/source/oleada2.o: source/oleada2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/oleada2.o source/oleada2.cpp

${OBJECTDIR}/source/pbBehavior.o: source/pbBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/pbBehavior.o source/pbBehavior.cpp

${OBJECTDIR}/source/pistolaBehavior.o: source/pistolaBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/pistolaBehavior.o source/pistolaBehavior.cpp

${OBJECTDIR}/source/pistolaBullet.o: source/pistolaBullet.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/pistolaBullet.o source/pistolaBullet.cpp

${OBJECTDIR}/source/player.o: source/player.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/player.o source/player.cpp

${OBJECTDIR}/source/sbBehavior.o: source/sbBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/sbBehavior.o source/sbBehavior.cpp

${OBJECTDIR}/source/sceneMenu.o: source/sceneMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/sceneMenu.o source/sceneMenu.cpp

${OBJECTDIR}/source/sceneSplash.o: source/sceneSplash.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/sceneSplash.o source/sceneSplash.cpp

${OBJECTDIR}/source/splash.o: source/splash.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/splash.o source/splash.cpp

${OBJECTDIR}/source/sprayParticleScript.o: source/sprayParticleScript.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/sprayParticleScript.o source/sprayParticleScript.cpp

${OBJECTDIR}/source/staticObject.o: source/staticObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/staticObject.o source/staticObject.cpp

${OBJECTDIR}/source/tile.o: source/tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/tile.o source/tile.cpp

${OBJECTDIR}/source/tileDestroyManager.o: source/tileDestroyManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/tileDestroyManager.o source/tileDestroyManager.cpp

${OBJECTDIR}/source/tileRow.o: source/tileRow.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/tileRow.o source/tileRow.cpp

${OBJECTDIR}/source/tilerJsonLoadScene.o: source/tilerJsonLoadScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/tilerJsonLoadScene.o source/tilerJsonLoadScene.cpp

${OBJECTDIR}/source/transitionScene.o: source/transitionScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/transitionScene.o source/transitionScene.cpp

${OBJECTDIR}/source/weapon.o: source/weapon.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibs/SFML-2.1/include -Ilibs/Box2D/include -Ilibs/json-c -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/weapon.o source/weapon.cpp

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
