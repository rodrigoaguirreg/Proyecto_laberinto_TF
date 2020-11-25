#pragma once
#include "Controladora.h"

namespace Proyectolaberinto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		CControladora* oControladora = new CControladora(3,60);//3 == vidas // 60 = tiempo
		Bitmap^ solido = gcnew Bitmap("sprites\\bmpSolido.png");
		Bitmap^ camino = gcnew Bitmap("sprites\\camino.png");
		Bitmap^ base = gcnew Bitmap("sprites\\bmpSolido.png");
		Bitmap^ prota = gcnew Bitmap("sprites\\protagonista.png");
		Bitmap^ Asesino = gcnew Bitmap("sprites\\asesino.png");
		Bitmap^ aliados = gcnew Bitmap("sprites\\aliados.png");
		Bitmap^ corrupto = gcnew Bitmap("sprites\\corrupto.png");
		int** matriz;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 465);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MantenerTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::ultimaTeclaPresionada);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		oControladora->dibujar(g, base, solido, camino, prota, aliados, corrupto, Asesino, matriz);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		oControladora->MapaAleatoria();
	}
	private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			oControladora->getoProta()->setDireccion(Direcciones::Arriba);
			break;
		case Keys::Down:
			oControladora->getoProta()->setDireccion(Direcciones::Abajo);
			break;
		case Keys::Left:
			oControladora->getoProta()->setDireccion(Direcciones::Izquierda);
			break;
		case Keys::Right:
			oControladora->getoProta()->setDireccion(Direcciones::Derecha);
			break;

		default:
			break;
		}
	}
	private: System::Void ultimaTeclaPresionada(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		default:
			oControladora->getoProta()->setDireccion(Direcciones::Ninguna);
			break;
		}
	}


	private: System::Void MantenerTeclaAliados(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			oControladora->getoAliados()->setDireccionn(Direccioness::Arribaa);
			break;
		case Keys::Down:
			oControladora->getoAliados()->setDireccionn(Direccioness::Abajoo);
			break;
		case Keys::Left:
			oControladora->getoAliados()->setDireccionn(Direccioness::Izquierdaa);
			break;
		case Keys::Right:
			oControladora->getoAliados()->setDireccionn(Direccioness::Derechaa);
			break;

		default:
			break;
		}
	}
	private: System::Void ultimaTeclaPresionadaAliados(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		default:
			oControladora->getoAliados()->setDireccion(Direcciones::Ninguna);
			break;
		}
	}
	};
}