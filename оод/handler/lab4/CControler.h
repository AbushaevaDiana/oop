﻿#pragma once
#include <iostream>
#include <sstream>
#include <functional>
#include "const.h"
#include "CShapeHandler.h"
#include "CUserInterface.h"
#include "CDragAndDropState.h"
#include "CFillShapeState.h"
#include "CFillBorderState.h"
#include "CWidthBorderState.h"

class CHandler
{
public:
	static CHandler* GetInstance(std::istream& input, std::ostream& output, sf::RenderWindow& window);

	void ReadShapes() const;
	void HandleEvent(sf::Event event);
	void PrintInfoAboutShapes() const;
	void Draw() const;

private:
	CHandler(std::istream& input, std::ostream& output, sf::RenderWindow& window);

	void DrawShapes() const;
	void DrawUserInterface() const;

	using Handler = std::function<void(std::istringstream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	const ActionMap m_actionMap;

	std::istream& m_input;
	std::ostream& m_output;
	sf::RenderWindow& m_window;

	static CHandler* m_instance;
	CShapeHandler* m_shapeHandler;
	CUserInterface* m_userInterface;
};