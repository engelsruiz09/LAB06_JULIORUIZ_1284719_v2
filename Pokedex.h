#pragma once
#include <msclr\marshal_cppstd.h>
#include "Lista.h"
#include "Orden.h"
#include "CsvReader.h"
#include "StopWatch.h"

namespace LAB06JULIORUIZ1284719 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Pokedex : public System::Windows::Forms::Form
	{
		Orden* orden;
		Lista* lista;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Label^ label3;

		   StopWatch* timer;
	public:
		Pokedex(void)
		{
			InitializeComponent();
			Leerarchivo("LISTAPOKEMONS2.csv");
			orden = new Orden();
			timer = new StopWatch();
		}

	protected:
		~Pokedex()
		{
			if (components)
			{
				delete components;
			}
		}
		void Leerarchivo(string ruta)
		{
			CsvReader* csv = new CsvReader(ruta);

			lista = new Lista();

			string numero;
			string nombre;
			string generacion;
			while (csv->Read(numero) && csv->Read(nombre) && csv->Read(generacion))
			{
				string texto = numero + " - " + nombre + " - " + generacion;
				Pokemon* nuevo = new Pokemon(stoi(numero), nombre, stoi(generacion), texto);
				lista->Insertar(nuevo);
			}

			LlenarDatos();
		}
		void LlenarDatos()
		{
			lbxPokedex->Items->Clear();
			for (int i = 0; i < lista->Size(); i++)
			{
				Pokemon* pkm = lista->ObtenerPokemon(i);
				lbxPokedex->Items->Add(gcnew String(pkm->ToString().c_str()));
			}
		}
	private: System::Windows::Forms::ListBox^ lbxPokedex;
	private: System::Windows::Forms::ComboBox^ cbxParametro;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cbxMetodo;
	private: System::Windows::Forms::Button^ btnOrdenar;
	protected:

	private:
		System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Pokedex::typeid));
			this->lbxPokedex = (gcnew System::Windows::Forms::ListBox());
			this->cbxParametro = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbxMetodo = (gcnew System::Windows::Forms::ComboBox());
			this->btnOrdenar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbxPokedex
			// 
			this->lbxPokedex->BackColor = System::Drawing::Color::DarkRed;
			this->lbxPokedex->ForeColor = System::Drawing::Color::White;
			this->lbxPokedex->FormattingEnabled = true;
			this->lbxPokedex->ItemHeight = 20;
			this->lbxPokedex->Location = System::Drawing::Point(80, 155);
			this->lbxPokedex->Name = L"lbxPokedex";
			this->lbxPokedex->Size = System::Drawing::Size(284, 404);
			this->lbxPokedex->TabIndex = 0;
			// 
			// cbxParametro
			// 
			this->cbxParametro->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxParametro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbxParametro->FormattingEnabled = true;
			this->cbxParametro->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Numero Nacional", L"Nombre", L"Generacion" });
			this->cbxParametro->Location = System::Drawing::Point(482, 200);
			this->cbxParametro->Name = L"cbxParametro";
			this->cbxParametro->Size = System::Drawing::Size(186, 26);
			this->cbxParametro->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(446, 155);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ordenar por:";
			// 
			// cbxMetodo
			// 
			this->cbxMetodo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxMetodo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbxMetodo->FormattingEnabled = true;
			this->cbxMetodo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Selection Sort", L"Quick Sort", L"Shell Sort" });
			this->cbxMetodo->Location = System::Drawing::Point(482, 305);
			this->cbxMetodo->Name = L"cbxMetodo";
			this->cbxMetodo->Size = System::Drawing::Size(186, 26);
			this->cbxMetodo->TabIndex = 4;
			// 
			// btnOrdenar
			// 
			this->btnOrdenar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOrdenar->Location = System::Drawing::Point(495, 351);
			this->btnOrdenar->Name = L"btnOrdenar";
			this->btnOrdenar->Size = System::Drawing::Size(150, 48);
			this->btnOrdenar->TabIndex = 5;
			this->btnOrdenar->Text = L"Ordenar";
			this->btnOrdenar->UseVisualStyleBackColor = true;
			this->btnOrdenar->Click += gcnew System::EventHandler(this, &Pokedex::btnOrdenar_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(446, 415);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Tiempo:";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->Location = System::Drawing::Point(584, 415);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(41, 18);
			this->lblTiempo->TabIndex = 7;
			this->lblTiempo->Text = L"0 ms";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(428, 258);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 18);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Ordenamiento por:";
			// 
			// Pokedex
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(790, 640);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnOrdenar);
			this->Controls->Add(this->cbxMetodo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbxParametro);
			this->Controls->Add(this->lbxPokedex);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Pokedex";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pokedex";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnOrdenar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (cbxParametro->SelectedIndex != -1 && cbxMetodo->SelectedIndex != -1)
		{
			string parametro = "";
			if (cbxParametro->SelectedIndex == 0)
				parametro = "numero";
			if (cbxParametro->SelectedIndex == 1)
				parametro = "nombre";
			if (cbxParametro->SelectedIndex == 2)
				parametro = "generacion";

			timer->Start();
			if (cbxMetodo->SelectedIndex == 0)
				orden->SelectionSort(lista, parametro);
			if (cbxMetodo->SelectedIndex == 1)
				orden->QuickSort(lista, parametro);
			if (cbxMetodo->SelectedIndex == 2)
				orden->ShellSort(lista, parametro);
			lblTiempo->Text = timer->End() + "ms";
		}
		LlenarDatos();
	}
};
}
