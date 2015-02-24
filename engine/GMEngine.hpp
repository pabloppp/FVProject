/* 
 * File:   GMEngine.hpp
 * Author: pablopernias
 *
 * Created on 12 de febrero de 2015, 1:34
 */

#ifndef GMENGINE_HPP
#define	GMENGINE_HPP

//includes...
//BASE CLASSES
#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp" //???
#include "Scene.hpp"

//COMPONENTS
#include "components/Script.hpp"
#include "components/Transform.hpp" //Lo incluimos???
#include "components/RigidBody.hpp" //???
#include "components/Renderer.hpp"  //???
//#include "components/Collider.hpp"  //???
#include "components/BoxCollider.hpp"
#include "components/CircleCollider.hpp"

//FACADES
#include "facade/Time.hpp"
#include "facade/Clock.hpp"
#include "facade/Keyboard.hpp"
#include "facade/Texture.hpp"
#include "facade/Vector2.hpp"
#include "facade/Window.hpp"
#include "facade/Mouse.hpp"


#endif	/* GMENGINE_HPP */

