// Plik naglowkowy z forma
#include "FormCrane.h"

// Przestrzeni nazw niezbedne do tworzenia i wywolania metod (funkcji skladowych) w tym pliku (cpp)
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]										// Ten atrybut musi byc obecny w punkcie wejscia (w tym przypadku funkcji main) dowolnej aplikacji Windows Forms
void main(array<String^>^ args) {
	Application::EnableVisualStyles();						// Wywolanie niezbednych metod do zarzadzania aplikacja
	Application::SetCompatibleTextRenderingDefault(false);	// -//-

	Project4::FormCrane form;								// Tworzenie zmiennej formularza (dalej - "formy") klasy FormWSA przestrzeni nazw Project3WSA
	Application::Run(% form);								// Uruchamianie formy 
}

// Wspolrzedne
struct OXY {
	int X, Y;
};


OXY direction;		// Kierunek 
OXY position;		// Polozenie
OXY actionArea;		// Pole, na ktorym odbywa sie ruch

// Konstruktor
Project4::FormCrane::FormCrane(void)
{
	InitializeComponent();						// Ladowanie strony komponentow

	actionArea.X = 330;
	actionArea.Y = 480;

	blocks = gcnew array<PictureBox^, 1> (3);	// Tworzenie tablicy blokow
	blocks[0] = block1;
	blocks[1] = block2;
	blocks[2] = block3;
}

// Metoda startujaca 
void Project4::FormCrane::NewSimulation()
{
	pictureBoxArea->Controls->Remove(hook);			// Usuwanie haka dzwigowego

	hook = gcnew PictureBox();						// Tworzenie nowego haka oraz nadanie parametrow poczatkowych 
	hook->Width = step;
	hook->Height = step;
	hook->Location = Point(0, 0);
	hook->Image = Image::FromFile("bracing.jpg");

	pictureBoxArea->Controls->Add(hook);			// Dodanie haka do pictureBoxArea

	GenerateBlockPositions();

	timer->Interval = updateInterval;
	timer->Start();									// Start timer'a

	direction.X = 1;								// Kierunek poczatkowy
	direction.Y = 0;

	work = true;
}


void Project4::FormCrane::GenerateBlockPositions()
{
	Random^ rand = gcnew Random();								// Zmienna losowa

	for (int i = 0; i < 3; i++)									// Usuniecie wszystkich blokow z pictureBoxArea
		pictureBoxArea->Controls->Remove(blocks[i]);			

	for (int i = 0; i < 3; i++) {								// Cykl tworzenia trzech blokow i nadania parametrow poczatkowych
		blocks[i] = gcnew PictureBox();								

		blocks[i]->Width = step;
		blocks[i]->Height = step;

		position.Y = 450;

		position.X = rand->Next(0, actionArea.X);				// Losowe polozenie po X (od 0 do actionArea.X = 330)

		// Dodanie zdjecia do bloku oraz warunki, aby bloki nie nakladaly sie na siebie
		if (i == 0) {
			blocks[i]->Image = Image::FromFile("square.jpg");
		}
		else if (i == 1) {
			blocks[i]->Image = Image::FromFile("triangle.jpg");

			while ( (position.X <= blocks[i - 1]->Location.X + step && position.X >= blocks[i - 1]->Location.X - step) ) {
				position.X = rand->Next(0, actionArea.X);
			}
		}
		else {
			blocks[i]->Image = Image::FromFile("circle.jpg");

			while ((position.X <= blocks[i - 1]->Location.X + step && position.X >= blocks[i - 1]->Location.X - step) || (position.X <= blocks[i - 2]->Location.X + step && position.X >= blocks[i - 2]->Location.X - step)) {
				position.X = rand->Next(0, actionArea.X);
			}
		}

		int temp = position.X % step;							// Operacja, ktora pozwala otrzymac wspolrzedna podzielna przez skok (czyli 30)
		position.X -= temp;

		blocks[i]->Location = Point(position.X, position.Y);	// Nadanie polozenia

		pictureBoxArea->Controls->Add(blocks[i]);				// Dodanie bloku do pictureBoxArea
	}
}

// Przemieszczenie haka
void Project4::FormCrane::MovementHook()
{	
	Pen^ redPen = gcnew Pen(Color::Black, 1.0F);			// Obiekt do rysowania linii i krzywych
	Graphics^ thread = pictureBoxArea->CreateGraphics();	// Obiekt umozliwiajacy rysowanie w pictureBoxArea
	
	MovementDirection();

	hook->Location = Point(hook->Location.X + direction.X * step, hook->Location.Y + direction.Y * step);	// Nadanie nowego polozenia

	pictureBoxArea->Refresh();								// Odnowienie pola - ponownie narysowaс wszystkie elementy
	thread->DrawLine(redPen, hook->Location.X + step/2, 0, hook->Location.X + step/2, hook->Location.Y);	// Rysowanie linki dzwigu
}

// Nadanie kierunku w zaleznosci od etapu 
void Project4::FormCrane::MovementDirection()
{
	if (stage == 1 && hook->Location.X == blocks[1]->Location.X) {
		direction.X = 0;
		direction.Y = 1;

		stage = 2;
	}
	else if (stage == 2 && hook->Location.Y + 30 == blocks[1]->Location.Y) {
		direction.X = 0;
		direction.Y = -1;

		stage = 3;
	}
	else if (stage == 3 && hook->Location.Y == 240) {
		if (hook->Location.X > blocks[0]->Location.X) {
			direction.X = -1;
			direction.Y = 0;

			stage = 4;
		}
		else if (hook->Location.X < blocks[0]->Location.X) {
			direction.X = 1;
			direction.Y = 0;

			stage = 4;
		}
		else if (hook->Location.X == blocks[0]->Location.X) {
			direction.X = 0;
			direction.Y = 1;

			stage = 4;
		}
	}
	else if (stage == 4 && hook->Location.X == blocks[0]->Location.X) {
		direction.X = 0;
		direction.Y = 1;

		stage = 5;
	}
	else if (stage == 5 && hook->Location.Y + 60 == blocks[0]->Location.Y) {
		direction.X = 0;
		direction.Y = -1;

		stage = 6;
	}
	else if (stage == 6 && hook->Location.Y == 240) {
		if (hook->Location.X > blocks[2]->Location.X) {
			direction.X = -1;
			direction.Y = 0;

			stage = 7;
		}
		else if (hook->Location.X < blocks[2]->Location.X) {
			direction.X = 1;
			direction.Y = 0;

			stage = 7;
		}
		else if (hook->Location.X == blocks[2]->Location.X) {
			direction.X = 0;
			direction.Y = 1;

			stage = 7;
		}
	}
	else if (stage == 7 && hook->Location.X == blocks[2]->Location.X) {
		direction.X = 0;
		direction.Y = 1;

		stage = 8;
	}
	else if (stage == 8 && hook->Location.Y + 30 == blocks[2]->Location.Y) {
		direction.X = 0;
		direction.Y = -1;

		stage = 9;
	}
	else if (stage == 9 && hook->Location.Y == 240) {
		if (hook->Location.X > blocks[0]->Location.X) {
			direction.X = -1;
			direction.Y = 0;

			stage = 10;
		}
		else if (hook->Location.X < blocks[0]->Location.X) {
			direction.X = 1;
			direction.Y = 0;

			stage = 10;
		}
		else if (hook->Location.X == blocks[0]->Location.X) {
			direction.X = 0;
			direction.Y = 1;

			stage = 10;
		}
	}
	else if (stage == 10 && hook->Location.X == blocks[0]->Location.X) {
		direction.X = 0;
		direction.Y = 1;

		stage = 11;
	}
	else if (stage == 11 && hook->Location.Y + 90 == blocks[0]->Location.Y) {
		direction.X = 0;
		direction.Y = 0;

		work = false;
	}
}

// Przemieszczenie blokow w zaleznosci od etapu 
void Project4::FormCrane::MovementBlocks()
{
	switch (stage) 
	{
	case 3 : 
		blocks[1]->Location = Point(blocks[1]->Location.X + direction.X * step, blocks[1]->Location.Y + direction.Y * step);
		break;
	case 4 :
		blocks[1]->Location = Point(blocks[1]->Location.X + direction.X * step, blocks[1]->Location.Y + direction.Y * step);
		break;
	case 5 :
		blocks[1]->Location = Point(blocks[1]->Location.X + direction.X * step, blocks[1]->Location.Y + direction.Y * step);
		break;
	case 9 :
		blocks[2]->Location = Point(blocks[2]->Location.X + direction.X * step, blocks[2]->Location.Y + direction.Y * step);
		break;
	case 10 :
		blocks[2]->Location = Point(blocks[2]->Location.X + direction.X * step, blocks[2]->Location.Y + direction.Y * step);
		break;
	case 11 :
		blocks[2]->Location = Point(blocks[2]->Location.X + direction.X * step, blocks[2]->Location.Y + direction.Y * step);
		break;
	default :
		break;
	}
}

// Metoda startujaca - po nacisnieciu przycisku buttonPrint
System::Void Project4::FormCrane::buttonBlock_Click(System::Object^ sender, System::EventArgs^ e)
{	
	stage = 1;
	pictureBoxArea->Refresh();	

	NewSimulation();
}

// Metoda ktora wywoluje sie co 350 milisekundy (event timer'a)
void Project4::FormCrane::FormCrane_Update(Object^ object, EventArgs^ e)
{
	if (work) {
		MovementHook();
		MovementBlocks();
	}
	else {
		timer->Stop();								// Zatrzymac timer
		MessageBox::Show("Zrobione!", "Wow!");
	}
}
