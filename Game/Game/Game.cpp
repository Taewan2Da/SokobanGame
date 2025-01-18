#include "Game.h"
#include <iostream>
#include <stdio.h>

#include "Level/MenuLevel.h"

Game* Game::instance = nullptr;

Game::Game()
	: Engine()
{
	instance = this;

	menuLevel = new MenuLevel();
}

Game::~Game()
{
	if (showMenu)
	{
		delete backLevel;
		backLevel = nullptr;
		mainLevel = nullptr;
	}
	else
	{
		delete mainLevel;
		mainLevel = nullptr;
	}

	delete menuLevel;
	menuLevel = nullptr;
}

void Game::ToggleMenu()
{
	system("cls");
	//Clear();
	showMenu = !showMenu;
	if (showMenu)
	{
		backLevel = mainLevel;
		mainLevel = menuLevel;
	}
	else
	{
		mainLevel = backLevel;
	}
}

////타이틀 화면 
//void Game::TitleScreen()
//{
//
//	std::string space1(10, ' ');  //공백을 생성
//	std::string space2(20, ' ');  //공백을 생성
//
//
//	system("cls");	
//	//타이틀 
//	std::cout << "@   @  @@@@@  @@@@    @@@           @@@     @    @   @  @@@@@\n";
//	std::cout << "@@ @@    @    @   @  @   @         @       @ @   @@ @@  @\n";
//	std::cout << "@ @ @    @    @@@@   @   @         @ @@@  @@@@@  @ @ @  @@@@\n";
//	std::cout << "@ @ @    @    @  @   @   @         @  @   @   @  @ @ @  @\n";
//	std::cout << "@   @  @@@@@  @   @   @@@           @@@   @   @  @   @  @@@@@\n";
//	std::cout << "\n\n";
//	std::cout << "                  Press enterkey to start\n";
//
//	 //엔터키가 눌리지 않으면 계속 대기
//	while (!Engine::Get().GetKeyDown(VK_RETURN)) {}
//	
//	getchar(); // 아무키 입력 기다림(인데 엔터키쳐야 넘어가짐)
//
//	system("cls");
//
//
//	//게임 설명
//	std::cout << " @@@     @    @   @  @@@@@         @@@@   @   @  @      @@@@@\n";
//	std::cout << "@       @ @   @@ @@  @             @   @  @   @  @      @\n";
//	std::cout << "@ @@@  @@@@@  @ @ @  @@@@          @@@@   @   @  @      @@@@\n";
//	std::cout << "@  @   @   @  @ @ @  @             @  @   @   @  @      @\n";
//	std::cout << " @@@   @   @  @   @  @@@@@         @   @   @@@   @@@@@  @@@@@\n";
//	std::cout << "\n\n";
//	std::cout << space1 << "1. 미로의 정보는 공개하지 않고 게임을 시작한다.\n";
//	std::cout << space1 << "2. 미로에는 가상의벽이 존재한다.\n";
//	std::cout << space1 << "3. 가상의 벽을 넘어가면 시작 지점으로 되돌아간다.\n";
//	std::cout << "\n\n\n\n";
//
//	std::cout << space2 << "     [ 조작법 ] \n\n";
//	std::cout << space2 << "이동: W, A, S, D\n";
//	std::cout << space2 << "      ↑, ←, ↓, →\n";
//
//
//	getchar(); // 아무키 입력 기다림(인데 엔터키쳐야 넘어가짐)
//
//	system("cls");
//}

//엔딩 화면 
void Game::EndingScreen()
{
	system("cls");
		//엔딩
		std::cout << " @@@     @    @   @  @@@@@          @@@@  @      @@@@@    @    @@@@\n";
		std::cout << "@       @ @   @@ @@  @             @      @      @       @ @   @   @\n";
		std::cout << "@ @@@  @@@@@  @ @ @  @@@@          @      @      @@@@   @@@@@  @@@@\n";
		std::cout << "@  @   @   @  @ @ @  @             @      @      @      @   @  @  @\n";
		std::cout << " @@@   @   @  @   @  @@@@@          @@@@  @@@@@  @@@@@  @   @  @   @\n";

		std::cout << "\n\n";
		std::cout << "                  Press enterkey to close\n";
		Sleep(1000);
		system("cls");

		// 게임 종료 처리.
		exit(0);  //이게 문제임 Engine::Get().QuitGame();

//		Engine::Get().QuitGame(); //이게 문제임
}

