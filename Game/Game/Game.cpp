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

////Ÿ��Ʋ ȭ�� 
//void Game::TitleScreen()
//{
//
//	std::string space1(10, ' ');  //������ ����
//	std::string space2(20, ' ');  //������ ����
//
//
//	system("cls");	
//	//Ÿ��Ʋ 
//	std::cout << "@   @  @@@@@  @@@@    @@@           @@@     @    @   @  @@@@@\n";
//	std::cout << "@@ @@    @    @   @  @   @         @       @ @   @@ @@  @\n";
//	std::cout << "@ @ @    @    @@@@   @   @         @ @@@  @@@@@  @ @ @  @@@@\n";
//	std::cout << "@ @ @    @    @  @   @   @         @  @   @   @  @ @ @  @\n";
//	std::cout << "@   @  @@@@@  @   @   @@@           @@@   @   @  @   @  @@@@@\n";
//	std::cout << "\n\n";
//	std::cout << "                  Press enterkey to start\n";
//
//	 //����Ű�� ������ ������ ��� ���
//	while (!Engine::Get().GetKeyDown(VK_RETURN)) {}
//	
//	getchar(); // �ƹ�Ű �Է� ��ٸ�(�ε� ����Ű�ľ� �Ѿ��)
//
//	system("cls");
//
//
//	//���� ����
//	std::cout << " @@@     @    @   @  @@@@@         @@@@   @   @  @      @@@@@\n";
//	std::cout << "@       @ @   @@ @@  @             @   @  @   @  @      @\n";
//	std::cout << "@ @@@  @@@@@  @ @ @  @@@@          @@@@   @   @  @      @@@@\n";
//	std::cout << "@  @   @   @  @ @ @  @             @  @   @   @  @      @\n";
//	std::cout << " @@@   @   @  @   @  @@@@@         @   @   @@@   @@@@@  @@@@@\n";
//	std::cout << "\n\n";
//	std::cout << space1 << "1. �̷��� ������ �������� �ʰ� ������ �����Ѵ�.\n";
//	std::cout << space1 << "2. �̷ο��� �����Ǻ��� �����Ѵ�.\n";
//	std::cout << space1 << "3. ������ ���� �Ѿ�� ���� �������� �ǵ��ư���.\n";
//	std::cout << "\n\n\n\n";
//
//	std::cout << space2 << "     [ ���۹� ] \n\n";
//	std::cout << space2 << "�̵�: W, A, S, D\n";
//	std::cout << space2 << "      ��, ��, ��, ��\n";
//
//
//	getchar(); // �ƹ�Ű �Է� ��ٸ�(�ε� ����Ű�ľ� �Ѿ��)
//
//	system("cls");
//}

//���� ȭ�� 
void Game::EndingScreen()
{
	system("cls");
		//����
		std::cout << " @@@     @    @   @  @@@@@          @@@@  @      @@@@@    @    @@@@\n";
		std::cout << "@       @ @   @@ @@  @             @      @      @       @ @   @   @\n";
		std::cout << "@ @@@  @@@@@  @ @ @  @@@@          @      @      @@@@   @@@@@  @@@@\n";
		std::cout << "@  @   @   @  @ @ @  @             @      @      @      @   @  @  @\n";
		std::cout << " @@@   @   @  @   @  @@@@@          @@@@  @@@@@  @@@@@  @   @  @   @\n";

		std::cout << "\n\n";
		std::cout << "                  Press enterkey to close\n";
		Sleep(1000);
		system("cls");

		// ���� ���� ó��.
		exit(0);  //�̰� ������ Engine::Get().QuitGame();

//		Engine::Get().QuitGame(); //�̰� ������
}

