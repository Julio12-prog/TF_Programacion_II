#pragma once
#include"JuegoControladora.h"

namespace JuegoTF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class JuegoForm : public System::Windows::Forms::Form
	{
	private:	
		//Declaracion de la clase controladora referenciada
		JuegoControladora^ juego;
		
	public:
		JuegoForm()
		{
			InitializeComponent();
			//Inicializacion de la clase controladora
			juego = gcnew JuegoControladora();
			
		}

	protected:
		
		~JuegoForm()
		{
			if (components)
			{
				delete components;
				
			}
			delete juego;
		}
	private: System::Windows::Forms::Timer^ clock;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
	


#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 33;
			this->clock->Tick += gcnew System::EventHandler(this, &JuegoForm::clock_Tick);
			// 
			// JuegoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(896, 827);
			this->Name = L"JuegoForm";
			this->Text = L"JuegoForm";
			this->Load += gcnew System::EventHandler(this, &JuegoForm::JuegoForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoForm::JuegoForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoForm::JuegoForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void clock_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Buffer
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);


		bf->Graphics->Clear(Color::White);
		
		juego->Mover(bf->Graphics);
		juego->Mostrar(bf->Graphics);

		bf->Render(g);
	}
		  
	private: System::Void JuegoForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//Evento Key down si se presiona una tecla, el jugador se mueve
		juego->MoverJugador(true, e->KeyCode);
	}

	private: System::Void JuegoForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//Evento key up si se suelta una tecla el jugador no se mueve
		juego->MoverJugador(false, e->KeyCode);
	}
	private: System::Void JuegoForm_Load(System::Object^ sender, System::EventArgs^ e) { //Load del laberinto
		juego->GenerarLab();
	}

	};
}
