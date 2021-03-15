/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{100,100};
	int xwin=800, ywin=1000;

	Simple_window win (tl,xwin,ywin,"Window");

	Lines grid;

	for(int x=100;x<xwin;x+=100)
	{
		grid.add(Point{x,0},Point(x,800));
	}

	for(int y=100;y<ywin;y+=100)
	{
		grid.add(Point{0,y},Point(800,y));
	}	

	win.attach(grid);

	Vector_ref<Graph_lib::Rectangle> squares;

	for(int i=0;i<8;i++)
	{
		squares.push_back(new Rectangle {Point{i*100,i*100}, 100, 100});
		squares[i].set_fill_color(Color::red);
		win.attach(squares[i]);
	}

	Image image2_1 {Point{200, 0}, "image2.jpg"};
	win.attach(image2_1);
	Image image2_2 {Point{0,200}, "image2.jpg"};
	win.attach(image2_2);
	Image image2_3 {Point{200,400}, "image2.jpg"};
	win.attach(image2_3);
	Image image2_4 {Point{400,600}, "image2.jpg"};
	win.attach(image2_4);

	Image image1 {Point{0,0}, "image1.jpg"};
	win.attach(image1);

	win.wait_for_button();

	int moves=0;
	while(true)
	{
		for(int i=0;i<7;i++)
		{
			image1.move(100,0);
			moves++;
			win.wait_for_button();
		}
		if(moves==55)
		{
			moves=0;
			image1.move(-700,-700);
		}
		else
		{
			image1.move(-700,100);
		}
		win.wait_for_button();
	}
	

	win.wait_for_button();
}