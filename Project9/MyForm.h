#pragma once
#include "Clasesop.h"

namespace Project9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public:
	private:
		Mapa* nuevo;
		Mapa* nuevo2;
		BufferedGraphics^ buffer;
		Bitmap^ imgBomberman;
		Graphics^ g;
		Bitmap^ tile1;
		Bitmap^ tile2;
		Bitmap^ tile3;
		Bitmap^ tile4;
		Bitmap^ tile5;
		Bitmap^ fondo;
		Bitmap^ fondoMenucito;
	private: System::Windows::Forms::Button^  btn2V2;
	private: System::Windows::Forms::Button^  btn1v1;

	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::PictureBox^  fonditoWe;
	private: System::Windows::Forms::Timer^  timer3;

			 Bitmap^ Bomber;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn2V2 = (gcnew System::Windows::Forms::Button());
			this->btn1v1 = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->fonditoWe = (gcnew System::Windows::Forms::PictureBox());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fonditoWe))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// btn2V2
			// 
			this->btn2V2->Location = System::Drawing::Point(438, 234);
			this->btn2V2->Name = L"btn2V2";
			this->btn2V2->Size = System::Drawing::Size(138, 73);
			this->btn2V2->TabIndex = 4;
			this->btn2V2->Text = L"Multijugador";
			this->btn2V2->UseVisualStyleBackColor = true;
			this->btn2V2->Click += gcnew System::EventHandler(this, &MyForm::btn2V2_Click);
			// 
			// btn1v1
			// 
			this->btn1v1->Location = System::Drawing::Point(99, 234);
			this->btn1v1->Name = L"btn1v1";
			this->btn1v1->Size = System::Drawing::Size(138, 73);
			this->btn1v1->TabIndex = 3;
			this->btn1v1->Text = L"Un Jugador";
			this->btn1v1->UseVisualStyleBackColor = true;
			this->btn1v1->Click += gcnew System::EventHandler(this, &MyForm::btn1v1_Click);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// fonditoWe
			// 
			this->fonditoWe->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fonditoWe.Image")));
			this->fonditoWe->Location = System::Drawing::Point(-2, -27);
			this->fonditoWe->Name = L"fonditoWe";
			this->fonditoWe->Size = System::Drawing::Size(704, 448);
			this->fonditoWe->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->fonditoWe->TabIndex = 5;
			this->fonditoWe->TabStop = false;
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 386);
			this->Controls->Add(this->btn2V2);
			this->Controls->Add(this->btn1v1);
			this->Controls->Add(this->fonditoWe);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Bomberman";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fonditoWe))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
		tile1 = gcnew Bitmap("5.png");
		tile2 = gcnew Bitmap("1.png");
		tile3 = gcnew Bitmap("2.png");
		tile4 = gcnew Bitmap("3.png");
		tile5 = gcnew Bitmap("4.png");
		fondo = gcnew Bitmap("ElfonditoWe.png");
		Bomber = gcnew Bitmap("Bomberman_Enemies.png");
		fondoMenucito = gcnew Bitmap("White_Bomber.jpg");
		Bomber->MakeTransparent(Bomber->GetPixel(0, 0));
		nuevo = new Mapa(1);
		nuevo2 = new Mapa(2);
		

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buffer = context->Allocate(g, this->ClientRectangle);
		Bomber->MakeTransparent(Bomber->GetPixel(1, 1));
		nuevo->Dibujar(buffer, Bomber, tile1, tile2, tile3, tile4, tile5, 1, false, fondo);
		buffer->Render(g);
		delete g;
		
		delete buffer;
		delete context;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		
		switch (e->KeyCode)
		{
		case Keys::Tab:
			nuevo->sigmapa();
			nuevo2->sigmapa();
			break;
		case Keys::Up:
			   
				nuevo->Getjug(1)->SetDirec(Direcciones::Arriba);
			if(timer3->Enabled)
				nuevo2->Getjug(1)->SetDirec(Direcciones::Arriba);
				//nuevo->Getjug(1)->moverse(false);
			
			break;
		case Keys::Down:
			
				nuevo->Getjug(1)->SetDirec(Direcciones::Abajo);
				if (timer3->Enabled)
					nuevo2->Getjug(1)->SetDirec(Direcciones::Abajo);
				//nuevo->Getjug(1)->moverse(false);
			
			break;
		case Keys::Left:
			
				nuevo->Getjug(1)->SetDirec(Direcciones::Izquierda);
				if (timer3->Enabled)
					nuevo2->Getjug(1)->SetDirec(Direcciones::Izquierda);
				//nuevo->Getjug(1)->moverse(false);
			
			break;
		case Keys::Right:
			

				nuevo->Getjug(1)->SetDirec(Direcciones::Derecha);
				if (timer3->Enabled)
					nuevo2->Getjug(1)->SetDirec(Direcciones::Derecha);
				//nuevo->Getjug(1)->moverse(false);
			
			break;
		case Keys::W:

			if (timer3->Enabled)
				nuevo2->Getjug(2)->SetDirec(Direcciones::Arriba);
			//nuevo->Getjug(1)->moverse(false);

			break;
		case Keys::S:

			
			if (timer3->Enabled)
				nuevo2->Getjug(2)->SetDirec(Direcciones::Abajo);
			//nuevo->Getjug(1)->moverse(false);

			break;
		case Keys::A:

			if (timer3->Enabled)
				nuevo2->Getjug(2)->SetDirec(Direcciones::Izquierda);
			//nuevo->Getjug(1)->moverse(false);

			break;
		case Keys::D:
			if (timer3->Enabled)
				nuevo2->Getjug(2)->SetDirec(Direcciones::Derecha);
			//nuevo->Getjug(1)->moverse(false);

			break;
		case Keys::NumPad0:
			nuevo->Getjug(1)->NuevaBomba(nuevo->map());
			if (timer3->Enabled)
				nuevo2->Getjug(1)->NuevaBomba(nuevo2->map());
			break;
		case Keys::Space:
			if (timer3->Enabled)
				nuevo2->Getjug(2)->NuevaBomba(nuevo2->map());
			break;
		case Keys::Escape:
			timer1->Enabled = false;
            fonditoWe->Visible = true;
			btn1v1->Enabled = true;
			btn2V2->Enabled = true;
			btn1v1->Visible = true;
			btn2V2->Visible = true;
			this->Width = 711;
			this->Height = 425;
			break;
		default:
			nuevo->Getjug(1)->SetDirec(Direcciones::ninguna);
			break;

		}
		/*if(nuevo->get_coli()){ nuevo->Getjug(1)->SetDirec(Direcciones::ninguna); }
		else if(!nuevo->get_coli())
		{
			nuevo->set_coli(false);
		}*/
		
	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if(timer1->Enabled)
			nuevo->Getjug(1)->SetDirec(ninguna);
		if (timer3->Enabled) {
			if (e->KeyData == Keys::Up || e->KeyData == Keys::Down || e->KeyData == Keys::Right || e->KeyData == Keys::Left)
				nuevo2->Getjug(1)->SetDirec(ninguna);
			if (e->KeyData == Keys::W || e->KeyData == Keys::S || e->KeyData == Keys::D || e->KeyData == Keys::A )
				nuevo2->Getjug(2)->SetDirec(ninguna);
		}

		/*if (nuevo->get_coli()) { nuevo->Getjug(1)->SetDirec(Direcciones::ninguna); }
		else if (!nuevo->get_coli())
		{
			nuevo->set_coli(false);
		}*/
	}
private: System::Void btn2V2_Click(System::Object^  sender, System::EventArgs^  e) {
	fonditoWe->Visible = false;
	btn1v1->Visible = false;
	btn1v1->Enabled = false;
	btn2V2->Visible = false;
	btn2V2->Enabled = false;
	this->Width = 495;
	this->Height = 520;
	timer3->Enabled = true;
}
private: System::Void btn1v1_Click(System::Object^  sender, System::EventArgs^  e) {
	fonditoWe->Visible = false;
	btn1v1->Visible = false;
	btn1v1->Enabled = false;
	btn2V2->Visible = false;
	btn2V2->Enabled = false;
	this->Width = 495;
	this->Height = 520;
	timer1->Enabled = true;
	
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (nuevo->Getjug(1)->get_vidas() == 0) {
		timer2->Enabled = false;
		MessageBox::Show("Moriste");
		MyForm::Close();
	}
}
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
	g = this->CreateGraphics();
	BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
	buffer = context->Allocate(g, this->ClientRectangle);
	Bomber->MakeTransparent(Bomber->GetPixel(1, 1));


	nuevo2->Dibujar(buffer, Bomber, tile1, tile2, tile3, tile4, tile5, 1, false, fondo);
	buffer->Render(g);
	delete g;

	delete buffer;
	delete context;
}
};
}
