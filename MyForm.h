#pragma once
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include "Lista.h"
#include "Orden.h"
#include "CsvReader.h"

namespace LAB06JULIORUIZ1284719 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::ComboBox^ cBMetodoOrdenamiento;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cBCriteriosOrdenamiento;
	private: System::Windows::Forms::Button^ btnOrdenar;
	private: System::Windows::Forms::RichTextBox^ rtbListaPokemons;
	private: System::Windows::Forms::Button^ btnSelecrArchivo;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

		   Lista* lista;
	public:
		MyForm()
		{
			InitializeComponent();
			Leerarchivo("LISTAPOKEMONS2.csv");
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		void Leerarchivo(string ruta)
		{
			CsvReader* csv = new CsvReader(ruta);

			lista = new Lista();

			string numero;
			string nombre;
			string generacion;
			while (csv->Read(numero) && csv->Read(nombre) && csv->Read(generacion))
			{
				//Pokemon* nuevo = new Pokemon(stoi(numero), nombre, stoi(generacion));
				//lista->Insertar(nuevo);
			}

			LlenarDatos();
		}
		void LlenarDatos()
		{

		}

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->cBMetodoOrdenamiento = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cBCriteriosOrdenamiento = (gcnew System::Windows::Forms::ComboBox());
			this->btnOrdenar = (gcnew System::Windows::Forms::Button());
			this->rtbListaPokemons = (gcnew System::Windows::Forms::RichTextBox());
			this->btnSelecrArchivo = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// cBMetodoOrdenamiento
			// 
			this->cBMetodoOrdenamiento->BackColor = System::Drawing::Color::DarkRed;
			this->cBMetodoOrdenamiento->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cBMetodoOrdenamiento->ForeColor = System::Drawing::Color::White;
			this->cBMetodoOrdenamiento->FormattingEnabled = true;
			this->cBMetodoOrdenamiento->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Selection Sort", L"Quick Sort", L"Shell Sort" });
			this->cBMetodoOrdenamiento->Location = System::Drawing::Point(281, 352);
			this->cBMetodoOrdenamiento->Name = L"cBMetodoOrdenamiento";
			this->cBMetodoOrdenamiento->Size = System::Drawing::Size(223, 26);
			this->cBMetodoOrdenamiento->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(270, 327);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(254, 17);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Elegir  el método de ordenamiento:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(289, 261);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(227, 17);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Elegir  el criterio de búsqueda:";
			// 
			// cBCriteriosOrdenamiento
			// 
			this->cBCriteriosOrdenamiento->BackColor = System::Drawing::Color::DarkRed;
			this->cBCriteriosOrdenamiento->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cBCriteriosOrdenamiento->ForeColor = System::Drawing::Color::White;
			this->cBCriteriosOrdenamiento->FormattingEnabled = true;
			this->cBCriteriosOrdenamiento->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"National Number", L"Generation Number" });
			this->cBCriteriosOrdenamiento->Location = System::Drawing::Point(281, 291);
			this->cBCriteriosOrdenamiento->Name = L"cBCriteriosOrdenamiento";
			this->cBCriteriosOrdenamiento->Size = System::Drawing::Size(223, 26);
			this->cBCriteriosOrdenamiento->TabIndex = 10;
			// 
			// btnOrdenar
			// 
			this->btnOrdenar->BackColor = System::Drawing::Color::Chartreuse;
			this->btnOrdenar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOrdenar->Location = System::Drawing::Point(281, 189);
			this->btnOrdenar->Name = L"btnOrdenar";
			this->btnOrdenar->Size = System::Drawing::Size(223, 52);
			this->btnOrdenar->TabIndex = 9;
			this->btnOrdenar->Text = L"Ordenar Lista";
			this->btnOrdenar->UseVisualStyleBackColor = false;
			// 
			// rtbListaPokemons
			// 
			this->rtbListaPokemons->BackColor = System::Drawing::Color::Maroon;
			this->rtbListaPokemons->Location = System::Drawing::Point(49, 96);
			this->rtbListaPokemons->Name = L"rtbListaPokemons";
			this->rtbListaPokemons->Size = System::Drawing::Size(200, 226);
			this->rtbListaPokemons->TabIndex = 8;
			this->rtbListaPokemons->Text = L"";
			// 
			// btnSelecrArchivo
			// 
			this->btnSelecrArchivo->BackColor = System::Drawing::Color::Chartreuse;
			this->btnSelecrArchivo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSelecrArchivo->Location = System::Drawing::Point(281, 108);
			this->btnSelecrArchivo->Name = L"btnSelecrArchivo";
			this->btnSelecrArchivo->Size = System::Drawing::Size(223, 52);
			this->btnSelecrArchivo->TabIndex = 7;
			this->btnSelecrArchivo->Text = L"Seleccionar Archivo";
			this->btnSelecrArchivo->UseVisualStyleBackColor = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(545, 423);
			this->Controls->Add(this->cBMetodoOrdenamiento);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cBCriteriosOrdenamiento);
			this->Controls->Add(this->btnOrdenar);
			this->Controls->Add(this->rtbListaPokemons);
			this->Controls->Add(this->btnSelecrArchivo);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pokédex";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
};
}
