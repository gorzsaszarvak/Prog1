/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
try{
    
    using namespace Graph_lib;

    Point tl{100, 100};

    Simple_window win {tl, 600, 400, "My window"};

//12.7.3

	Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
	Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
	ya.set_color(Color::white);
	ya.label.set_color(Color::white);

//12.7.4

	Function sine(sin, 0, 100, Point(20,150),1000,25,25);
	sine.set_color(Color::red);

//12.7.5

	Polygon poly;
	poly.add(Point(200,100));
	poly.add(Point(200,50));
	poly.add(Point(300,100));

	poly.set_color(Color::black);


//12.7.6/1

	Rectangle r(Point(200,100), 100, 100);
	r.set_color(Color::black);


//12.7.6/2
 
	Closed_polyline poly_rect;
	poly_rect.add(Point(150,50));
	poly_rect.add(Point(200,50));
	poly_rect.add(Point(200,100));
	poly_rect.add(Point(150,100));
	poly_rect.add(Point(50,75));


//12.7.7

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);


//12.7.8

	Text t(Point(150,150), "Graphic design is my passion");

	t.set_font(Font::times_bold);
	t.set_font_size(15);
	t.set_color(Color::blue);

//12.7.9

	Image ii{Point{100,50}, "image.jpg"};

//12.7.10

	Circle c(Point(100,200),75);

	Mark m(Point(100,205),'x');

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max();
	Text sizes(Point(100,20),oss.str());

	win.attach(ii);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(c);
	win.attach(m);
	win.attach(sizes);


    win.wait_for_button();

}
catch(exception& e){
	cerr << "Error" << endl;
	return 1;
}
catch(...){
	cerr << "Error" << endl;
	return 2;
}