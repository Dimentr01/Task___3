#include <iostream>
#include <SFML/Graphics.hpp>
#include "PieChart.hpp"
#include "Robber.h"
#include "Helper.h"

void draw2(robbers Robber[], int& lifes)
{
	
	// will draw chart for horses
	int total_horses = 0;
	int life_robbers = 0;
	
	for (int i = 0; i < lifes; i++)
	{
		if (Robber[i].life == 1)
		{
			life_robbers++;
			total_horses += Robber[i].horses;
		}
	}

	if(life_robbers == 0)
	{
		std::cout << "Нет живых разбойников" << std::endl;
		return;
	}
	sf::Font font;
	if (!font.loadFromFile("ArialBlack/ArialBlack.ttf"))
	{
		std::cout << "can not load font from ArialBlack/ArialBlack.ttf" << std::endl;
		return;
	}
	
	
	// Количество лошадей 
	int* horses_life_robbers = new int[life_robbers];
	// Цвета
	int **colors_life_robbers = new int*[life_robbers];

	// Подписи
	sf::Text* texts = new sf::Text[life_robbers + 2];
	// Столбцовая диаграмма
	sf::RectangleShape* shapes = new sf::RectangleShape[life_robbers];

	float rect_ident = 5.;
	float pie_chart_size = 300;
	int min_width = 1024;
	int min_height = 768;
	int title_size = 25;
	
	float rect_size_with_ident = (min_width / 2 + pie_chart_size / 2) / life_robbers;
	int name_size = 25;
	if (life_robbers > 28)
	{
		name_size = (min_height - title_size - rect_ident) / life_robbers;
	}
	
	int count = 0;
	int max_horse = -1;
	
	for (int i = 0; i < lifes; i++)
	{
		if (Robber[i].life == 1)
		{
			// Цвета
			colors_life_robbers[count] = new int[3];
			colors_life_robbers[count][0] = (std::rand() + std::rand() % 256 * count) % 256;
			colors_life_robbers[count][1] = (std::rand() + std::rand() % 256 * count) % 256;
			colors_life_robbers[count][2] = (std::rand() + std::rand() % 256 * count) % 256;	

			horses_life_robbers[count] = Robber[i].horses;

			// Подписи заполняю
			std::wstring text_text = L": ";
			std::wstring s_text = string_to_wstring(Robber[i].name) + text_text + std::to_wstring(Robber[i].horses);
			
			texts[count] = sf::Text(s_text, font);

			texts[count].setCharacterSize(name_size);
			texts[count].setFillColor(sf::Color(colors_life_robbers[count][0], colors_life_robbers[count][1], colors_life_robbers[count][2]));
			texts[count].setPosition(0, title_size + rect_ident + name_size * count);

			if (Robber[i].horses > max_horse)
				max_horse = Robber[i].horses;
			
			count++;
		}
	}
	
	// Заголовки
	texts[count] = sf::Text("Life robbers:", font);
	texts[count].setCharacterSize(title_size);
	//names_text.setStyle(sf::Text::Bold);
	texts[count].setFillColor(sf::Color::Black);
	texts[count].setPosition(0, 0);
	count++;

	texts[count] = sf::Text("Horses charts:", font);
	texts[count].setCharacterSize(title_size);
	//charts_text.setStyle(sf::Text::Bold);
	texts[count].setFillColor(sf::Color::Black);
	texts[count].setPosition(min_width / 2 + 100, 0);
	count++;
	
	sf::RenderWindow window(sf::VideoMode(min_width, min_height), "Chart");
	sw::PieChart pieChart;
	
	if(total_horses != 0)
	{
		int current_shift = 0;
		for (int i = 0; i < life_robbers; i++)
		{
			float part_size = float(horses_life_robbers[i]) / total_horses;
			pieChart.slices.resize(life_robbers);
			pieChart.slices[i].color = sf::Color(colors_life_robbers[i][0], colors_life_robbers[i][1], colors_life_robbers[i][2]);
			pieChart.slices[i].size = part_size;

			shapes[i] = sf::RectangleShape();
			shapes[i].setFillColor(sf::Color(colors_life_robbers[i][0], colors_life_robbers[i][1], colors_life_robbers[i][2]));
			
			shapes[i].setSize(sf::Vector2f(rect_size_with_ident - rect_ident, -horses_life_robbers[i] * (min_height - title_size - pie_chart_size - 3 * rect_ident ) / max_horse));
			shapes[i].setPosition(float(min_width / 2 + current_shift - pie_chart_size / 2), min_height);
			
			current_shift += rect_size_with_ident;
		}

		pieChart.setSize({ pie_chart_size, pie_chart_size });
		pieChart.update();
		pieChart.setOrigin(pieChart.getSize() / 2.f);
		pieChart.setPosition(min_width / 2, pie_chart_size / 2 + title_size + rect_ident);
	}

	// Рисование
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		window.draw(pieChart);
		for (int i = 0; i < count; i++)
		{
			window.draw(texts[i]);
		}
		
		for (int i = 0; i < life_robbers; i++)
		{
			window.draw(shapes[i]);
		}

		window.display();
	}

	delete[] horses_life_robbers;
	for (int i = 0; i < life_robbers; i++)
		delete[] colors_life_robbers[i];
	delete[] colors_life_robbers;
	delete[] texts;
	delete[] shapes;
}

void draw(robbers Robber[], int& lifes, int& swealth)
{
			float a1=0, a2=0, a3=0, a4=0, a5=0, b=0, h1=0, h2=0, h3=0, h4=0, h5=0,q1=0,q2=0,q3=0,q4=0,q5=0,g=0;
			for (int i = 0; i < lifes+1; i++)
			{
				if (Robber[i].life == 1)
				{
					q1 = Robber[i].horses + q1;
					g = g + Robber[i].wifes;
					q2 = q2 + Robber[i].sabers;
					q3 = q3 + Robber[i].rubies;
					q4 = q4 + Robber[i].necklaces;
					q5 = q5 + Robber[i].money;
				}
			}
			a1 = 500 * q1; b = swealth + 200 * g;
			a2 = 100 * q2;
			a3 = 50 * q3;
			a4 = 10 * q4;
			a5 = q5;
			h1 = a1 / b;
			h2 = a2 / b;
			h3 = a3 / b;
			h4 = a4 / b;
			h5 = a5 / b;

			sf::RenderWindow window(sf::VideoMode(480, 424), "Chart");
			sw::PieChart pieChart;
			pieChart.slices.resize(5);
			pieChart.slices[0].color = sf::Color::Red;
			pieChart.slices[1].color = sf::Color::Green;
			pieChart.slices[2].color = sf::Color::Blue;
			pieChart.slices[3].color = sf::Color(100, 100, 100);
			pieChart.slices[4].color = sf::Color::Yellow;

			pieChart.slices[0].size = h1;
			pieChart.slices[1].size = h2;
			pieChart.slices[2].size = h3;
			pieChart.slices[3].size = h4;
			pieChart.slices[4].size = h5;

			pieChart.setSize({ 100.f, 100.f });
			pieChart.update();
			pieChart.setOrigin(pieChart.getSize() / 2.f);
			pieChart.setPosition(50, 200);

			sf::Font font;
			if (!font.loadFromFile("ArialBlack/ArialBlack.ttf"))
			{
				std::cout << "// error..." << std::endl;
			}
			sf::Text text("horses-red", font);
			text.setFont(font);
			text.setCharacterSize(20);
			text.setStyle(sf::Text::Bold);
			text.setFillColor(sf::Color::Red);
			text.setPosition(0, 0);
			sf::Text text0("sabers-green", font);
			text0.setFont(font);
			text0.setCharacterSize(20);
			text0.setStyle(sf::Text::Bold);
			text0.setFillColor(sf::Color::Green);
			text0.setPosition(0, 20);
			sf::Text text1("rubies-blue", font);
			text1.setFont(font);
			text1.setCharacterSize(20);
			text1.setStyle(sf::Text::Bold);
			text1.setFillColor(sf::Color::Blue);
			text1.setPosition(0, 40);
			sf::Text text2("necklaces-green", font);
			text2.setFont(font);
			text2.setCharacterSize(20);
			text2.setStyle(sf::Text::Bold);
			text2.setFillColor(sf::Color(100, 100, 100));
			text2.setPosition(0, 60);
			sf::Text text3("money-yellow", font);
			text3.setFont(font);
			text3.setCharacterSize(20);
			text3.setStyle(sf::Text::Bold);
			text3.setFillColor(sf::Color::Yellow);
			text3.setPosition(0, 80);

			sf::ConvexShape convex;
			convex.setPointCount(4);
			convex.setPoint(0, sf::Vector2f(250.f, 150.f));
			convex.setPoint(1, sf::Vector2f(220.f, 150.f));
			convex.setPoint(2, sf::Vector2f(220.f, 150 - h1 * 100));
			convex.setPoint(3, sf::Vector2f(250.f, 150 - h1 * 100));
			convex.setFillColor(sf::Color::Red);
			sf::ConvexShape convex1;
			convex1.setPointCount(4);
			convex1.setPoint(0, sf::Vector2f(290.f, 150.f));
			convex1.setPoint(1, sf::Vector2f(260.f, 150.f));
			convex1.setPoint(2, sf::Vector2f(260.f, 150 - h2 * 100));
			convex1.setPoint(3, sf::Vector2f(290.f, 150 - h2 * 100));
			convex1.setFillColor(sf::Color::Green);
			sf::ConvexShape convex2;
			convex2.setPointCount(4);
			convex2.setPoint(0, sf::Vector2f(330.f, 150.f));
			convex2.setPoint(1, sf::Vector2f(300.f, 150.f));
			convex2.setPoint(2, sf::Vector2f(300.f, 150 - h3 * 100));
			convex2.setPoint(3, sf::Vector2f(330.f, 150 - h3 * 100));
			convex2.setFillColor(sf::Color::Blue);
			sf::ConvexShape convex3;
			convex3.setPointCount(4);
			convex3.setPoint(0, sf::Vector2f(370.f, 150.f));
			convex3.setPoint(1, sf::Vector2f(340.f, 150.f));
			convex3.setPoint(2, sf::Vector2f(340.f, 150 - h4 * 100));
			convex3.setPoint(3, sf::Vector2f(370.f, 150 - h4 * 100));
			convex3.setFillColor(sf::Color(100, 100, 100));
			sf::ConvexShape convex4;
			convex4.setPointCount(4);
			convex4.setPoint(0, sf::Vector2f(410.f, 150.f));
			convex4.setPoint(1, sf::Vector2f(380.f, 150.f));
			convex4.setPoint(2, sf::Vector2f(380.f, 150 - h5 * 100));
			convex4.setPoint(3, sf::Vector2f(410.f, 150 - h5 * 100));
			convex4.setFillColor(sf::Color::Yellow);

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				window.clear();
				window.draw(text);
				window.draw(text0);
				window.draw(text1);
				window.draw(text2);
				window.draw(text3);
				window.draw(pieChart);
				window.draw(convex);
				window.draw(convex1);
				window.draw(convex2);
				window.draw(convex3);
				window.draw(convex4);
				window.display();

			}
}
