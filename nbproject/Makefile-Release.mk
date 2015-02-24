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
	${OBJECTDIR}/engine/Component.o \
	${OBJECTDIR}/engine/Game.o \
	${OBJECTDIR}/engine/GameObject.o \
	${OBJECTDIR}/engine/Scene.o \
	${OBJECTDIR}/engine/components/BoxCollider.o \
	${OBJECTDIR}/engine/components/CircleCollider.o \
	${OBJECTDIR}/engine/components/Collider.o \
	${OBJECTDIR}/engine/components/Renderer.o \
	${OBJECTDIR}/engine/components/RigidBody.o \
	${OBJECTDIR}/engine/components/Script.o \
	${OBJECTDIR}/engine/components/Transform.o \
	${OBJECTDIR}/engine/facade/Clock.o \
	${OBJECTDIR}/engine/facade/Keyboard.o \
	${OBJECTDIR}/engine/facade/Mouse.o \
	${OBJECTDIR}/engine/facade/Texture.o \
	${OBJECTDIR}/engine/facade/Time.o \
	${OBJECTDIR}/engine/facade/Vector2.o \
	${OBJECTDIR}/engine/facade/Window.o \
	${OBJECTDIR}/engine/gameobjects/Camera.o \
	${OBJECTDIR}/hito1/hito1Game.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fvproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/engine/Component.o: engine/Component.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Component.o engine/Component.cpp

${OBJECTDIR}/engine/Game.o: engine/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Game.o engine/Game.cpp

${OBJECTDIR}/engine/GameObject.o: engine/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/GameObject.o engine/GameObject.cpp

${OBJECTDIR}/engine/Scene.o: engine/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/Scene.o engine/Scene.cpp

${OBJECTDIR}/engine/components/BoxCollider.o: engine/components/BoxCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/BoxCollider.o engine/components/BoxCollider.cpp

${OBJECTDIR}/engine/components/CircleCollider.o: engine/components/CircleCollider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/CircleCollider.o engine/components/CircleCollider.cpp

${OBJECTDIR}/engine/components/Collider.o: engine/components/Collider.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Collider.o engine/components/Collider.cpp

${OBJECTDIR}/engine/components/Renderer.o: engine/components/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Renderer.o engine/components/Renderer.cpp

${OBJECTDIR}/engine/components/RigidBody.o: engine/components/RigidBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/RigidBody.o engine/components/RigidBody.cpp

${OBJECTDIR}/engine/components/Script.o: engine/components/Script.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Script.o engine/components/Script.cpp

${OBJECTDIR}/engine/components/Transform.o: engine/components/Transform.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/components/Transform.o engine/components/Transform.cpp

${OBJECTDIR}/engine/facade/Clock.o: engine/facade/Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Clock.o engine/facade/Clock.cpp

${OBJECTDIR}/engine/facade/Keyboard.o: engine/facade/Keyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Keyboard.o engine/facade/Keyboard.cpp

${OBJECTDIR}/engine/facade/Mouse.o: engine/facade/Mouse.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Mouse.o engine/facade/Mouse.cpp

${OBJECTDIR}/engine/facade/Texture.o: engine/facade/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Texture.o engine/facade/Texture.cpp

${OBJECTDIR}/engine/facade/Time.o: engine/facade/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Time.o engine/facade/Time.cpp

${OBJECTDIR}/engine/facade/Vector2.o: engine/facade/Vector2.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Vector2.o engine/facade/Vector2.cpp

${OBJECTDIR}/engine/facade/Window.o: engine/facade/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/facade
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/facade/Window.o engine/facade/Window.cpp

${OBJECTDIR}/engine/gameobjects/Camera.o: engine/gameobjects/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/engine/gameobjects
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/engine/gameobjects/Camera.o engine/gameobjects/Camera.cpp

${OBJECTDIR}/hito1/hito1Game.o: hito1/hito1Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/hito1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hito1/hito1Game.o hito1/hito1Game.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
