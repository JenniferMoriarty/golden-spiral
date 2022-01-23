//golden spiral in SFML
//coded by Dr. Mo, Jan 2022
//dynamicsofanasteroid.com
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

int main()
{


	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Golden Spiral");
	cout << "Eadem mutata resurgo" << endl;
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(5, 5));


	float xpos;
	float ypos;
	float radius = 1;
	float angle = 0;
	int ticker = 0; //to change colors
	int adder = 1; //to change colors
	int i = 0; //iterator for loop
	float a=1;
	float k=.5;


	while (i<2000) {


		//basic logrithmic spiral
		//xpos = radius * cos(angle)+500;
		//ypos = radius * sin(angle)+500;

		//more measurable version
		//xpos = a*exp(k*angle) * cos(angle)+500;
		//ypos = a*exp(k*angle) * sin(angle)+500;


		//golden spiral
		xpos = sin(angle) * 1.618 * exp(angle / 3.14) + 500;
		ypos = cos(angle) * 1.618 * exp(angle / 3.14) + 500;

		//prints out coordinate points at every 90 degree angle
		if (i % 90 == 0)
			cout << "angle is " << angle << ", x and y are " << xpos - 500 << " , " << ypos - 500 << endl;
		
		angle = (i * 3.14) / 180; //increase angle (formula is to convert to radians)

		i++;
		//radius++ //uncomment this if you're experimenting with regular logarithmic spirals
		//window.clear();

		//make fun colors
		if (ticker > 254 || ticker<0) {
			adder *= -1;
		}
		ticker += adder;

		rectangle.setFillColor(sf::Color(ticker, 0, 250));
		rectangle.setPosition(xpos, ypos);
		window.draw(rectangle);
		window.display();
	}

	//this keeps it open after it's done drawing
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


	}



}



