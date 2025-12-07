#pragma once
#include <math.h>
#include <algorithm>

constexpr auto MAXX = 4;
constexpr auto MAX_X = 10;
constexpr auto MAX_Y = 10;
int nrDefecte = 0;

struct poarta {
	char tipP; //tipul portii
	int niv, poz; //nivelul si pozitia portii
	int ni; //numar intrari
	struct {
		int n; //nivelul intrarii
		int p; //pozitia intrarii
	}Intrare[MAXX]; //vectorul de intrari
	int stare; //0 - FN, 1 - blocaj pe conexiune
	int b; //0 -b0L, 1-b1L
	int vn; // valoare in functionalitate normala, combinatia de intrare se fixeaza aici (0, 1, -1)
	int ve; //valoarea eronata
	int* defecte; //vectorul cu defecte pentru fiecare poarta/intrare
}SLC[MAX_X][MAX_Y];

namespace DeductiveFaultSim {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Diagnostics;

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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::RichTextBox^ ScriptBox;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ raportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generateRaportToolStripMenuItem;


	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ RunSimButton;
	private: System::Windows::Forms::RichTextBox^ TimeBox;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^ ValorileDeductive;
	private: System::Windows::Forms::TextBox^ Values;
	private: System::Windows::Forms::ToolStripMenuItem^ generateTruthTableToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ classicSimulationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ resetToolStripMenuItem;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ScriptBox = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->raportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateRaportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateTruthTableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->classicSimulationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->RunSimButton = (gcnew System::Windows::Forms::Button());
			this->TimeBox = (gcnew System::Windows::Forms::RichTextBox());
			this->ValorileDeductive = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Values = (gcnew System::Windows::Forms::TextBox());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(376, 50);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(24, 19);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"ID";
			// 
			// ScriptBox
			// 
			this->ScriptBox->Location = System::Drawing::Point(12, 59);
			this->ScriptBox->Name = L"ScriptBox";
			this->ScriptBox->ReadOnly = true;
			this->ScriptBox->Size = System::Drawing::Size(324, 263);
			this->ScriptBox->TabIndex = 2;
			this->ScriptBox->Text = L"RichEdit";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->raportToolStripMenuItem, this->helpToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(635, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->addToolStripMenuItem,
					this->resetToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->addToolStripMenuItem->Text = L"Add File";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addToolStripMenuItem_Click);
			// 
			// raportToolStripMenuItem
			// 
			this->raportToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->generateRaportToolStripMenuItem,
					this->generateTruthTableToolStripMenuItem, this->classicSimulationToolStripMenuItem
			});
			this->raportToolStripMenuItem->Name = L"raportToolStripMenuItem";
			this->raportToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->raportToolStripMenuItem->Text = L"Raport";
			// 
			// generateRaportToolStripMenuItem
			// 
			this->generateRaportToolStripMenuItem->Name = L"generateRaportToolStripMenuItem";
			this->generateRaportToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->generateRaportToolStripMenuItem->Text = L"Generate Raport";
			this->generateRaportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::generateRaportToolStripMenuItem_Click);
			// 
			// generateTruthTableToolStripMenuItem
			// 
			this->generateTruthTableToolStripMenuItem->Name = L"generateTruthTableToolStripMenuItem";
			this->generateTruthTableToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->generateTruthTableToolStripMenuItem->Text = L"Generate Truth Table";
			this->generateTruthTableToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::generateTruthTableToolStripMenuItem_Click);
			// 
			// classicSimulationToolStripMenuItem
			// 
			this->classicSimulationToolStripMenuItem->Name = L"classicSimulationToolStripMenuItem";
			this->classicSimulationToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->classicSimulationToolStripMenuItem->Text = L"Classic Simulation";
			this->classicSimulationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::classicSimulationToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::MenuBar;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox2->Location = System::Drawing::Point(415, 50);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(51, 18);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"Name";
			// 
			// RunSimButton
			// 
			this->RunSimButton->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->RunSimButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->RunSimButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->RunSimButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RunSimButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->RunSimButton->Location = System::Drawing::Point(74, 328);
			this->RunSimButton->Name = L"RunSimButton";
			this->RunSimButton->Size = System::Drawing::Size(200, 23);
			this->RunSimButton->TabIndex = 9;
			this->RunSimButton->Text = L"Run Simulation";
			this->RunSimButton->UseVisualStyleBackColor = false;
			this->RunSimButton->Click += gcnew System::EventHandler(this, &MyForm::RunSimButton_Click);
			// 
			// TimeBox
			// 
			this->TimeBox->BackColor = System::Drawing::SystemColors::MenuBar;
			this->TimeBox->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeBox->Location = System::Drawing::Point(74, 27);
			this->TimeBox->Name = L"TimeBox";
			this->TimeBox->ReadOnly = true;
			this->TimeBox->Size = System::Drawing::Size(206, 26);
			this->TimeBox->TabIndex = 10;
			this->TimeBox->Text = L"";
			// 
			// ValorileDeductive
			// 
			this->ValorileDeductive->AutoSize = true;
			this->ValorileDeductive->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->ValorileDeductive->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				17.41425F)));
			this->ValorileDeductive->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.10818F)));
			this->ValorileDeductive->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				61.47757F)));
			this->ValorileDeductive->Location = System::Drawing::Point(364, 72);
			this->ValorileDeductive->Name = L"ValorileDeductive";
			this->ValorileDeductive->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.26984F)));
			this->ValorileDeductive->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 21.84466F)));
			this->ValorileDeductive->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.93204F)));
			this->ValorileDeductive->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 21.84466F)));
			this->ValorileDeductive->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 19.90291F)));
			this->ValorileDeductive->Size = System::Drawing::Size(255, 225);
			this->ValorileDeductive->TabIndex = 0;
			// 
			// Values
			// 
			this->Values->BackColor = System::Drawing::SystemColors::MenuBar;
			this->Values->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Values->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Values->Location = System::Drawing::Point(512, 50);
			this->Values->Name = L"Values";
			this->Values->Size = System::Drawing::Size(67, 19);
			this->Values->TabIndex = 11;
			this->Values->Text = L"Values";
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->resetToolStripMenuItem->Text = L"Reset Values";
			this->resetToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::resetToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(635, 362);
			this->Controls->Add(this->Values);
			this->Controls->Add(this->ValorileDeductive);
			this->Controls->Add(this->TimeBox);
			this->Controls->Add(this->RunSimButton);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->ScriptBox);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"DeductiveFaultSim";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	/// <summary>
	/// Incarca fisierul de circuit (.dfs) si populeaza structura de date 'SLC' + UI
	/// </summary>
	/// <param name="filePath"></param>
	/// <returns></returns>
	private: System::Void loadCircuitFile(String^ filePath) {
		//Curata UI-ul si reseteaza structura de date
		ScriptBox->Clear();
		ValorileDeductive->Controls->Clear();
		resetSLC();
		ValorileDeductive->RowCount = 0;
		ValorileDeductive->ColumnCount = 3;

		try {
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
			int x = 0, y = 0; 
			int idCounter = 1; 

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine()->Trim();
				if (String::IsNullOrEmpty(line)) continue;

				if (line->EndsWith(";")) {
					line = line->Substring(0, line->Length - 1);
				}

				ScriptBox->AppendText(line + Environment::NewLine);
				array<String^>^ tokens = line->Split(' ');
				if (tokens->Length == 0) continue;

				if (tokens[0] == "I") {
					//Procesam poarta de intrare
					if (tokens->Length < 2) {
						MessageBox::Show("Eroare: lipsesc date pentru INPUT in linia: " + line);
						continue;
					}

					ValorileDeductive->RowCount++;

					//Adaugam ID si eticheta pentru poarta
					Label^ idLabel = gcnew Label();
					idLabel->Text = idCounter.ToString();
					idLabel->AutoSize = true;
					ValorileDeductive->Controls->Add(idLabel, 0, ValorileDeductive->RowCount - 1);

					Label^ nameLabel = gcnew Label();
					nameLabel->Text = tokens[0] + ((tokens->Length > 1) ? (" " + tokens[1]) : "");
					nameLabel->AutoSize = true;
					ValorileDeductive->Controls->Add(nameLabel, 1, ValorileDeductive->RowCount - 1);

					try {
						//Extragem coordonatele portii logice
						array<String^>^ coord = tokens[1]->Split(',');
						if (coord->Length != 2) {
							MessageBox::Show("Format coordonate invalid: " + tokens[1]);
							continue;
						}
						int niv = Convert::ToInt32(coord[0]);
						int poz = Convert::ToInt32(coord[1]);

						//Initializam structura portii de intrare
						SLC[niv][poz].tipP = 'I';
						SLC[niv][poz].niv = niv;
						SLC[niv][poz].poz = poz;
						SLC[niv][poz].ni = 0;
						SLC[niv][poz].vn = -1;
						SLC[niv][poz].ve = -1;
						SLC[niv][poz].stare = 0;

						//Verificam daca exista blocaj
						int blocaj = -1;
						if (tokens->Length > 2 && tokens[2]->StartsWith("b")) {
							blocaj = tokens[2][1] - '0';
							SLC[niv][poz].stare = 1;
						}
						SLC[niv][poz].b = blocaj;
						SLC[niv][poz].ve = SLC[niv][poz].b;
						nrDefecte++;

						//Adaugam radio buttons pentru selectarea valorii initiale
						FlowLayoutPanel^ radioGroupPanel = gcnew FlowLayoutPanel();
						radioGroupPanel->FlowDirection = FlowDirection::LeftToRight;
						radioGroupPanel->AutoSize = true;
						radioGroupPanel->WrapContents = true;
						radioGroupPanel->Dock = DockStyle::Fill;
						radioGroupPanel->MaximumSize = System::Drawing::Size(this->ValorileDeductive->GetColumnWidths()[2], 0);

						RadioButton^ rb0 = createRadioButton(niv, poz, 0, blocaj);
						RadioButton^ rb1 = createRadioButton(niv, poz, 1, blocaj);

						if (rb0 != nullptr) {
							radioGroupPanel->Controls->Add(rb0);
						}
						if (rb1 != nullptr) {
							radioGroupPanel->Controls->Add(rb1);
						}

						ValorileDeductive->SetColumnSpan(radioGroupPanel, 1);
						ValorileDeductive->Controls->Add(radioGroupPanel, 2, ValorileDeductive->RowCount - 1);

					}
					catch (FormatException^ ex) {
						MessageBox::Show("Eroare la conversia valorilor pentru INPUT: " + ex->Message);
					}
				}
				else {
					//Procesam o poarta logica (AND, OR, XOR etc.)
					try {
						if (tokens->Length < 4) {
							MessageBox::Show("Eroare: lipsesc date pentru poarta logica in linia: " + line);
							continue;
						}

						Char tipPoarta = tokens[0][0];
						if (tipPoarta != 'a' && tipPoarta != 'o' && tipPoarta != 'x' &&
							tipPoarta != 'N' && tipPoarta != 'B' && tipPoarta != 'A' && tipPoarta != 'O' && tipPoarta != 'X') {
							MessageBox::Show("Tip poarta invalid: " + tokens[0]);
							continue;
						}

						array<String^>^ coord = tokens[1]->Split(',');
						if (coord->Length != 2) {
							MessageBox::Show("Format coordonate invalid: " + tokens[1]);
							continue;
						}

						int niv = Convert::ToInt32(coord[0]);
						int poz = Convert::ToInt32(coord[1]);

						SLC[niv][poz].tipP = (char)tipPoarta;
						SLC[niv][poz].niv = niv;
						SLC[niv][poz].poz = poz;
						SLC[niv][poz].vn = -1;
						SLC[niv][poz].ve = -1;
						SLC[niv][poz].stare = 0;
						nrDefecte++;

						//Parseaza numarul de intrari
						int ni;
						if (!Int32::TryParse(tokens[2], ni) || ni <= 0) {
							MessageBox::Show("Numar de intrari invalid: " + tokens[2]);
							continue;
						}
						SLC[niv][poz].ni = ni;

						//Parseaza coordonatele intrarilor
						for (int i = 0; i < ni; i++) {
							array<String^>^ inCoord = tokens[3 + i]->Split(',');
							if (inCoord->Length != 2) {
								MessageBox::Show("Format coordonate intrare invalid: " + tokens[3 + i]);
								SLC[niv][poz].ni = 0;
								continue;
							}
							SLC[niv][poz].Intrare[i].n = Convert::ToInt32(inCoord[0]);
							SLC[niv][poz].Intrare[i].p = Convert::ToInt32(inCoord[1]);
						}
						//Verificam blocajul (daca este specificat)
						int blocaj = -1;
						if (tokens->Length > 3 + ni && tokens[3 + ni]->StartsWith("b")) {
							blocaj = tokens[3 + ni][1] - '0';
							SLC[niv][poz].stare = 1;
						}
						SLC[niv][poz].b = blocaj;
						SLC[niv][poz].ve = (blocaj != -1) ? blocaj : -1;
					}
					catch (FormatException^ ex) {
						MessageBox::Show("Eroare la conversia valorilor pentru poarta logica: " + ex->Message);
					}
				}

				idCounter++;
				y++;
				if (y >= MAX_Y) { y = 0; x++; }
			}
			reader->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Eroare la citirea fisierului: " + ex->Message);
		}
	}
	/// <summary>
	/// Creeaza un buton RadioButton pentru alegerea valorii de intrare (0 sau 1) pentru o poarta logica.
	/// Marcheaza butonul ca selectat daca valoarea corespunde unui blocaj specific.
	/// </summary>
	/// <param name="nivel">Nivelul (linia) in matricea circuitului</param>
	/// <param name="pozitie">Pozitia (coloana) in nivelul curent</param>
	/// <param name="value">Valoarea logica reprezentata de buton (0 sau 1)</param>
	/// <param name="blocaj">Valoarea blocata impusa de fisierul de intrare</param>
	/// <returns></returns>
	private: RadioButton^ createRadioButton(int nivel, int pozitie, int value, int blocaj) {
		if (value < 0) {
			return nullptr;
		}

		RadioButton^ rb = gcnew RadioButton();
		rb->Text = value.ToString();
		rb->AutoSize = true;
		rb->Tag = gcnew Tuple<int, int, int>(nivel, pozitie, value);
		rb->Margin = System::Windows::Forms::Padding(2, 2, 5, 2);
		rb->Checked = (blocaj == value && blocaj != -1);

		if (value == 0 && blocaj == -1) {
			rb->Checked = true;
		}

		return rb;
	}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	/// <summary>
	/// Functie handler de eveniment - butonul "Add File"
	/// </summary>
	/// <param name="sender">Obiectul care a generat evenimentul</param>
	/// <param name="e">Argumentele evenimentului</param>
	/// <returns></returns>
	private: System::Void addToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Fisier Deductive Fault Simulator (*.dfs)|*.dfs";
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				loadCircuitFile(openFileDialog->FileName);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Eroare la incarcarea fisierului: " + ex->Message);
			}
		}
	}
	/// <summary>
	/// Functie pentru incarcarea valorilor din RadioButtons in structura SLC
	/// </summary>
	/// <param name="nivel">Nivelul intrarii</param>
	/// <param name="pozitie">Pozitia intrarii</param>
	/// <returns></returns>
	private: int getRadioValue(int nivel, int pozitie) {
		for (int row = 0; row < ValorileDeductive->RowCount; row++) {
			FlowLayoutPanel^ panel = dynamic_cast<FlowLayoutPanel^>(ValorileDeductive->GetControlFromPosition(2, row));

			if (panel == nullptr) {
				continue;
			}

			for each(Control ^ control in panel->Controls) {
				RadioButton^ rb = dynamic_cast<RadioButton^>(control);
				if (rb != nullptr) {
					Tuple<int, int, int>^ tag = dynamic_cast<Tuple<int, int, int>^>(rb->Tag);
					if (tag != nullptr) {
						if (tag->Item1 == nivel && tag->Item2 == pozitie) {
							if (rb->Checked) {
								int value = tag->Item3;
								SLC[nivel][pozitie].vn = value;
								return value;
							}
						}
					}
				}
			}
		}
		return -1;
	}
	/// <summary>
	/// Determina toate iesirile logice aflate pe nivelul maxim din circuit.
	/// Se completeaza vectorii cu pozitiile acestora si seteaza 'nrIesiri'
	/// Foarte bun pentru identificarea iesirilor (sa stiu unde sa ma opresc)
	/// </summary>
	array<int>^ iesiriX = gcnew array<int>(10);
	array<int>^ iesiriY = gcnew array<int>(10);
	int nrIesiri = 0;
	private: void determinaIesiriLaNivelMax(array<int>^ iesiriX, array<int>^ iesiriY, int% nrIesiri) {
		int maxNivel = 0;
		nrIesiri = 0;
		for (int x = 0; x < MAX_X; x++) {
			for (int y = 0; y < MAX_Y; y++) {
				if (SLC[x][y].tipP != '\0') {
					if (SLC[x][y].niv > maxNivel) {
						maxNivel = SLC[x][y].niv;
						nrIesiri = 0;
						iesiriX[nrIesiri] = x;
						iesiriY[nrIesiri] = y;
						nrIesiri++;
					}
					else if (SLC[x][y].niv == maxNivel) {
						iesiriX[nrIesiri] = x;
						iesiriY[nrIesiri] = y;
						nrIesiri++;
					}
				}
			}
		}
	}
	/// <summary>
	/// Functie pentru resetarea structurii SLC
	/// </summary>
	private: void resetSLC() {
		for (int nivel = 0; nivel < MAX_X; nivel++) {
			for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
				SLC[nivel][pozitie].tipP = '\0';
				SLC[nivel][pozitie].vn = -1;
				SLC[nivel][pozitie].ve = -1;
				SLC[nivel][pozitie].stare = 0;
				if (SLC[nivel][pozitie].defecte != nullptr) {
					delete[] SLC[nivel][pozitie].defecte;
					SLC[nivel][pozitie].defecte = nullptr;
				}
				nrDefecte = 0;
			}
		}
		timer->Restart();
		TimeBox->Text = "Time Simulation: 0 ms";
	}
	/// <summary>
	/// Functie pentru resetarea valorilor
	/// </summary>
	private: void resetValues() {
		for (int nivel = 0; nivel < MAX_X; nivel++) {
			for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
				if (SLC[nivel][pozitie].stare != 1) {
					SLC[nivel][pozitie].ve = -1;
				}
				SLC[nivel][pozitie].vn = -1;
				if (SLC[nivel][pozitie].defecte != nullptr) {
					delete[] SLC[nivel][pozitie].defecte;
					SLC[nivel][pozitie].defecte = nullptr;
				}
			}
		}
	}
	/// <summary>
	/// Functie pentru calcularea valorilor in regim normal (prima etapa simulare deductiva)
	/// </summary>
	/// <param name="x">Nivel</param>
	/// <param name="y">Pozitie</param>
	/// <returns></returns>
	private: int calculeazaValoarePoarta(int x, int y) {
		//Iau valoarea de pe fan out, nu mai calculez din nou
		if (SLC[x][y].vn != -1) {
			return SLC[x][y].vn;
		}
		//Iau valoarea din radio butoane
		if (SLC[x][y].tipP == 'I') {
			int value = getRadioValue(x, y);
			return (SLC[x][y].vn = value);
		}

		if (SLC[x][y].ni < 1) return -1;

		int valoareIntrari = -1;
		bool toateIntrarileValide = true;

		for (int i = 0; i < SLC[x][y].ni; i++) {
			int nivelIntrare = SLC[x][y].Intrare[i].n;
			int pozIntrare = SLC[x][y].Intrare[i].p;

			//Calculam valoarea fiecarei intrari (recursiv daca nu e input direct)
			int valoareIntrare = (SLC[nivelIntrare][pozIntrare].tipP == 'I') ?
				getRadioValue(nivelIntrare, pozIntrare) :
				calculeazaValoarePoarta(nivelIntrare, pozIntrare);

			if (valoareIntrare == -1) {
				toateIntrarileValide = false;
				break;
			}

			//Aplicam operatie logica specifica in functie de tipul portii
			if (valoareIntrari == -1) {
				valoareIntrari = valoareIntrare;
			}
			else {
				switch (SLC[x][y].tipP) {
				case 'a': valoareIntrari &= valoareIntrare; break; //AND
				case 'o': valoareIntrari |= valoareIntrare; break; //OR
				case 'x': valoareIntrari ^= valoareIntrare; break; //XOR
				case 'A': valoareIntrari = !(valoareIntrari & valoareIntrare); break; //NAND
				case 'O': valoareIntrari = !(valoareIntrari | valoareIntrare); break; //NOR
				case 'X': valoareIntrari = !(valoareIntrari ^ valoareIntrare); break; //NXOR
				default: return -1; break;
				}
			}
		}
		//NOT & BUFFER (daca le calculez in switch nu mai merge, le am facut separat si merge)
		if (SLC[x][y].tipP == 'N' || SLC[x][y].tipP == 'B') {
			if (SLC[x][y].ni != 1) return -1;
			int nivelIntrare = SLC[x][y].Intrare[0].n;
			int pozIntrare = SLC[x][y].Intrare[0].p;

			int valoareIntrare = (SLC[nivelIntrare][pozIntrare].tipP == 'I') ?
				getRadioValue(nivelIntrare, pozIntrare) :
				calculeazaValoarePoarta(nivelIntrare, pozIntrare);

			if (valoareIntrare == -1) return -1;
			valoareIntrari = (SLC[x][y].tipP == 'N') ? 1 - valoareIntrare : valoareIntrare;
		}
		//Salvam si returnam rezultatul
		int result = (toateIntrarileValide ? valoareIntrari : -1);
		return (SLC[x][y].vn = result);
	}
	/// <summary>
	/// Face acelasi lucru ca calculeazaValoarePoarta, doar ca nu este cu radio butoane si cu generare de combinatii
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	private: int evalueazaPoarta(int x, int y) {
		if (SLC[x][y].vn != -1)
			return SLC[x][y].vn;

		if (SLC[x][y].tipP == 'I')
			return SLC[x][y].vn;

		if (SLC[x][y].ni < 1)
			return -1;

		int valoareIntrari = -1;
		bool toateValide = true;

		for (int i = 0; i < SLC[x][y].ni; i++) {
			int nx = SLC[x][y].Intrare[i].n;
			int ny = SLC[x][y].Intrare[i].p;

			int val = (SLC[nx][ny].tipP == 'I') ? SLC[nx][ny].vn : evalueazaPoarta(nx, ny);

			if (val == -1) {
				toateValide = false;
				break;
			}

			if (valoareIntrari == -1)
				valoareIntrari = val;
			else {
				switch (SLC[x][y].tipP) {
				case 'a': valoareIntrari &= val; break;
				case 'o': valoareIntrari |= val; break;
				case 'x': valoareIntrari ^= val; break;
				case 'A': valoareIntrari = !(valoareIntrari & val); break;
				case 'O': valoareIntrari = !(valoareIntrari | val); break;
				case 'X': valoareIntrari = !(valoareIntrari ^ val); break;
				default: return -1;
				}
			}
		}

		if (SLC[x][y].tipP == 'N' || SLC[x][y].tipP == 'B') {
			if (SLC[x][y].ni != 1) return -1;
			int nx = SLC[x][y].Intrare[0].n;
			int ny = SLC[x][y].Intrare[0].p;

			int val = (SLC[nx][ny].tipP == 'I') ? SLC[nx][ny].vn : evalueazaPoarta(nx, ny);
			if (val == -1) return -1;

			valoareIntrari = (SLC[x][y].tipP == 'N') ? 1 - val : val;
		}

		int rezultat = toateValide ? valoareIntrari : -1;
		SLC[x][y].vn = rezultat;
		return rezultat;
	}
	/// <summary>
	/// Calculeaza valoarea in regim de blocaj pe o poarta/porti logica/logice
	/// </summary>
	/// <param name="x">Nivel</param>
	/// <param name="y">Pozitie</param>
	/// <returns></returns>
	private: int calculeazaValoareEronata(int x, int y) {
		if (SLC[x][y].ve != -1) {
			return SLC[x][y].ve;
		}
		if (SLC[x][y].tipP == 'I') {
			int value = getRadioValue(x, y);
			return (SLC[x][y].ve = value);
		}
		//Daca starea e in regim de blocaj, iau blocajul 
		if (SLC[x][y].stare == 1) {
			return (SLC[x][y].ve = SLC[x][y].b);
		}
		if (SLC[x][y].ni < 1) return -1;
		int valoareIntrari = -1;
		bool toateIntrarileValide = true;
		for (int i = 0; i < SLC[x][y].ni; i++) {
			int nivelIntrare = SLC[x][y].Intrare[i].n;
			int pozIntrare = SLC[x][y].Intrare[i].p;
			int valoareIntrare = (SLC[nivelIntrare][pozIntrare].tipP == 'I') ?
				getRadioValue(nivelIntrare, pozIntrare) :
				calculeazaValoareEronata(nivelIntrare, pozIntrare);
			if (valoareIntrare == -1) {
				toateIntrarileValide = false;
				break;
			}
			if (valoareIntrari == -1) {
				valoareIntrari = valoareIntrare;
			}
			else {
				switch (SLC[x][y].tipP) {
				case 'a': valoareIntrari &= valoareIntrare; break;
				case 'o': valoareIntrari |= valoareIntrare; break;
				case 'x': valoareIntrari ^= valoareIntrare; break;
				case 'A': valoareIntrari = !(valoareIntrari & valoareIntrare); break;
				case 'O': valoareIntrari = !(valoareIntrari | valoareIntrare); break;
				case 'X': valoareIntrari = !(valoareIntrari ^ valoareIntrare); break;
				default: return -1; break;
				}
			}
		}
		if (SLC[x][y].tipP == 'N' || SLC[x][y].tipP == 'B') {
			if (SLC[x][y].ni != 1) return -1;
			int nivelIntrare = SLC[x][y].Intrare[0].n;
			int pozIntrare = SLC[x][y].Intrare[0].p;

			int valoareIntrare = (SLC[nivelIntrare][pozIntrare].tipP == 'I') ?
				getRadioValue(nivelIntrare, pozIntrare) :
				calculeazaValoareEronata(nivelIntrare, pozIntrare);

			if (valoareIntrare == -1) return -1;

			valoareIntrari = (SLC[x][y].tipP == 'N') ? 1 - valoareIntrare : valoareIntrare;
		}
		int result = (toateIntrarileValide ? valoareIntrari : -1);
		return (SLC[x][y].ve = result);
	}
	/// <summary>
	/// Calculeaza un ID unic pentru poarta logica (x,y)
	/// - Se parcurge intreaga matrice SLC
	/// - La fiecare poarta valida, se incrementeaza un contor id
	/// - Daca poarta gasista este exact la coordonatele (x, y), se returneaza id
	/// </summary>
	/// <param name="x">Nivel</param>
	/// <param name="y">Pozitie</param>
	/// <returns></returns>
	private: int getGateId(int x, int y) {
		int id = 0;
		for (int i = 0; i < MAX_X; i++) {
			for (int j = 0; j < MAX_Y; j++) {
				if (SLC[i][j].tipP != '\0') {
					if (i == x && j == y) {
						return id;
					}
					id++;
				}
			}
		}
		return -1;
	}
	/// <summary>
	/// Face acelasi lucru ca calculeazaValoareEronata, doar ca pentru generare combinatii
	/// </summary>
	/// <param name="x">Nivel</param>
	/// <param name="y">Pozitie</param>
	/// <returns></returns>
	private: int evalueazaPoartaEronata(int x, int y) {
		if (SLC[x][y].tipP == 'I') {
			return SLC[x][y].ve;
		}
		if (SLC[x][y].ni < 1) {
			return -1;
		}
		if (SLC[x][y].stare == 1) {
			SLC[x][y].ve = SLC[x][y].b;
			return SLC[x][y].ve;
		}
		if (SLC[x][y].ve != -1) {
			return SLC[x][y].ve;
		}
		int valoareIntrari = -1;
		bool toateValide = true;

		for (int i = 0; i < SLC[x][y].ni; i++) {
			int nx = SLC[x][y].Intrare[i].n;
			int ny = SLC[x][y].Intrare[i].p;

			int val = (SLC[nx][ny].tipP == 'I') ? SLC[nx][ny].ve : evalueazaPoartaEronata(nx, ny);
			if (val == -1) {
				toateValide = false;
				break;
			}
			if (valoareIntrari == -1) {
				valoareIntrari = val;
			}
			else {
				switch (SLC[x][y].tipP) {
				case 'a': valoareIntrari &= val; break;
				case 'o': valoareIntrari |= val; break;
				case 'x': valoareIntrari ^= val; break;
				case 'A': valoareIntrari = !(valoareIntrari & val); break;
				case 'O': valoareIntrari = !(valoareIntrari | val); break;
				case 'X': valoareIntrari = !(valoareIntrari ^ val); break;
				default: return -1; break;
				}
			}
		}
		if (SLC[x][y].tipP == 'N' || SLC[x][y].tipP == 'B') {
			if (SLC[x][y].ni != 1) return -1;
			int nx = SLC[x][y].Intrare[0].n;
			int ny = SLC[x][y].Intrare[0].p;

			int val = (SLC[nx][ny].tipP == 'I') ? SLC[nx][ny].ve : evalueazaPoartaEronata(nx, ny);
			if (val == -1) return -1;

			valoareIntrari = (SLC[x][y].tipP == 'N') ? 1 - val : val;
		}
		int rezultat = toateValide ? valoareIntrari : -1;
		SLC[x][y].ve = rezultat;
		return rezultat;
	}
	/// <summary>
	/// Functie de mapare pe vector (ca pe vectorul meu o sa am 2 casute pentru fiecare poarta logica (b0/b1))
	/// Aici folosesc getGateId pentru a afla ID-ul unic al portii
	/// Ex: poarta (2,3) cu id = 4, atunci index_b0, index_b1 = 9 (locul unde trebuie sa atribui defectul pe poarta respectiva)
	/// </summary>
	/// <param name="x">Nivel</param>
	/// <param name="y">Pozitie</param>
	/// <returns></returns>
	/*
	* Exemplu cum arata indexarea pe circuit
	* I 1,1;
	I 1,2;
	I 1,3;
	I 1,4;
	N 2,1 1 1,1 b1;
	O 2,2 2 1,2 1,3;
	a 3,1 2 2,1 2,2;
	N 3,2 1 2,2;
	A 4,1 2 3,2 1,4;
	o 5,1 2 4,1 3,1;
	(1,1) ID = 0, indexii pentru (1,1) sunt 0,1
	(1,2) ID = 1, indexii pentru (1,2) sunt 2,3
	(1,3) ID = 2, indexii pentru (1,3) sunt 4,5 s.a.m.d
	*/
	private: Tuple<int, int>^ getIndexInput(int x, int y) {
		int gateId = getGateId(x, y);
		if (gateId == -1) return gcnew Tuple<int, int>(-1, -1);

		int index_b0 = 2 * gateId;
		int index_b1 = 2 * gateId + 1;
		return gcnew Tuple<int, int>(index_b0, index_b1);
	}
	/// <summary>
	/// Functie principala simulare deductiva (metoda buna, clara)
	/// </summary>
	/// <param name="x">Nivel</param>
	/// <param name="y">Pozitie</param>
	private: void propagaDefecte(int x, int y) {
		poarta& P = SLC[x][y];
		if (P.vn == -1) return;

		// Resetare vector defecte
		if (P.defecte != nullptr) {
			for (int i = 0; i < 2 * nrDefecte; i++) {
				P.defecte[i] = 0;
			}
		}

		Tuple<int, int>^ defectIndices = getIndexInput(x, y);
		int index_b0 = defectIndices->Item1;
		int index_b1 = defectIndices->Item2;

		// Tratare poarta de intrare
		if (P.tipP == 'I') {
			if (P.defecte != nullptr) {
				if (P.vn == 1 && index_b0 >= 0) P.defecte[index_b0] = 1;
				if (P.vn == 0 && index_b1 >= 0) P.defecte[index_b1] = 1;
			}
			return;
		}

		if (P.ni >= 1) {
			// Vector valori intrari
			array<int>^ inputValues = gcnew array<int>(P.ni);
			// Vector pointeri la defecte intrari
			array<bool*>^ inputDefects = gcnew array<bool*>(P.ni);

			for (int i = 0; i < P.ni; i++) {
				int input_nivel = P.Intrare[i].n;
				int input_poz = P.Intrare[i].p;
				inputValues[i] = SLC[input_nivel][input_poz].vn;

				inputDefects[i] = new bool[2 * nrDefecte]();
				if (SLC[input_nivel][input_poz].defecte != nullptr) {
					for (int j = 0; j < 2 * nrDefecte; j++) {
						inputDefects[i][j] = (SLC[input_nivel][input_poz].defecte[j] == 1);
					}
				}
			}

			if (P.defecte != nullptr) {
				for (int i = 0; i < 2 * nrDefecte; i++) {
					switch (P.tipP) {
					case 'a': // AND
						if (P.ni == 2) {
							if (inputValues[0] == 0 && inputValues[1] == 0 && P.vn == 0)
								P.defecte[i] = inputDefects[0][i] && inputDefects[1][i];
							else if (inputValues[0] == 0 && inputValues[1] == 1 && P.vn == 0)
								P.defecte[i] = inputDefects[0][i] && !inputDefects[1][i];
							else if (inputValues[0] == 1 && inputValues[1] == 0 && P.vn == 0)
								P.defecte[i] = inputDefects[1][i] && !inputDefects[0][i];
							else if (inputValues[0] == 1 && inputValues[1] == 1 && P.vn == 1)
								P.defecte[i] = inputDefects[0][i] || inputDefects[1][i];
							else
								P.defecte[i] = 0;
						}
						break;

					case 'A': // NAND
						if (P.ni == 2) {
							if (inputValues[0] == 0 && inputValues[1] == 0 && P.vn == 1)
								P.defecte[i] = inputDefects[0][i] && inputDefects[1][i];
							else if (inputValues[0] == 0 && inputValues[1] == 1 && P.vn == 1)
								P.defecte[i] = inputDefects[0][i] && !inputDefects[1][i];
							else if (inputValues[0] == 1 && inputValues[1] == 0 && P.vn == 1)
								P.defecte[i] = inputDefects[1][i] && !inputDefects[0][i];
							else if (inputValues[0] == 1 && inputValues[1] == 1 && P.vn == 0)
								P.defecte[i] = inputDefects[0][i] || inputDefects[1][i];
							else
								P.defecte[i] = 0;
						}
						break;

					case 'o': // OR
						if (P.ni == 2) {
							if (inputValues[0] == 1 && inputValues[1] == 1 && P.vn == 1)
								P.defecte[i] = inputDefects[0][i] && inputDefects[1][i];
							else if (inputValues[0] == 1 && inputValues[1] == 0 && P.vn == 1)
								P.defecte[i] = inputDefects[0][i] && !inputDefects[1][i];
							else if (inputValues[0] == 0 && inputValues[1] == 1 && P.vn == 1)
								P.defecte[i] = inputDefects[1][i] && !inputDefects[0][i];
							else if (inputValues[0] == 0 && inputValues[1] == 0 && P.vn == 0)
								P.defecte[i] = inputDefects[0][i] || inputDefects[1][i];
							else
								P.defecte[i] = 0;
						}
						break;

					case 'O': // NOR
						if (P.ni == 2) {
							if (inputValues[0] == 1 && inputValues[1] == 1 && P.vn == 0)
								P.defecte[i] = inputDefects[0][i] && inputDefects[1][i];
							else if (inputValues[0] == 1 && inputValues[1] == 0 && P.vn == 0)
								P.defecte[i] = inputDefects[0][i] && !inputDefects[1][i];
							else if (inputValues[0] == 0 && inputValues[1] == 1 && P.vn == 0)
								P.defecte[i] = inputDefects[1][i] && !inputDefects[0][i];
							else if (inputValues[0] == 0 && inputValues[1] == 0 && P.vn == 1)
								P.defecte[i] = inputDefects[0][i] || inputDefects[1][i];
							else
								P.defecte[i] = 0;
						}
						break;

					case 'x': // XOR
						if (P.ni == 2) {
							if (P.vn == (inputValues[0] ^ inputValues[1]))
								P.defecte[i] = (inputDefects[0][i] != inputDefects[1][i]);
							else
								P.defecte[i] = 0;
						}
						break;

					case 'X': // NXOR (XNOR)
						if (P.ni == 2) {
							if (P.vn == !(inputValues[0] ^ inputValues[1]))
								P.defecte[i] = (inputDefects[0][i] == inputDefects[1][i]);
							else
								P.defecte[i] = 0;
						}
						break;

					case 'N': // NOT
						if (P.ni == 1) {
							if (P.vn == (1 - inputValues[0]))
								P.defecte[i] = inputDefects[0][i];
							else
								P.defecte[i] = 0;
						}
						break;

					case 'B': // BUFFER
						if (P.ni == 1) {
							if (P.vn == inputValues[0])
								P.defecte[i] = inputDefects[0][i];
							else
								P.defecte[i] = 0;
						}
						break;

					default:
						P.defecte[i] = 0;
						break;
					}
				}
			}

			// Eliberare memorie temporara inputDefects
			for (int i = 0; i < P.ni; i++) {
				delete[] inputDefects[i];
			}
		}

		// Adaugă defectele de ieșire specifice b0 / b1
		if (P.defecte != nullptr) {
			if (P.vn == 1 && index_b0 >= 0) P.defecte[index_b0] = 1;
			if (P.vn == 0 && index_b1 >= 0) P.defecte[index_b1] = 1;
		}
	}
	Stopwatch^ timer = Stopwatch::StartNew();
	/// <summary>
	/// Evenimentul declansat la apasarea butonului de simulare. Ruleaza simularea logica si propagarea defectelor.
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void RunSimButton_Click(System::Object^ sender, System::EventArgs^ e) {
		//Pornire cronometru
		timer->Restart();
		//Determin iesiri
		determinaIesiriLaNivelMax(iesiriX, iesiriY, nrIesiri);
		//Initializare: curata si reseteaza starile tuturor portilor din matrice
		for (int nivel = 0; nivel < MAX_X; nivel++) {
			for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
				if (SLC[nivel][pozitie].tipP != '\0') {
					if (SLC[nivel][pozitie].defecte != nullptr) {
						delete[] SLC[nivel][pozitie].defecte;
						SLC[nivel][pozitie].defecte = nullptr;
					}
					SLC[nivel][pozitie].defecte = new int[2 * nrDefecte]();
					SLC[nivel][pozitie].vn = -1;
					if (SLC[nivel][pozitie].stare != 1) {
						SLC[nivel][pozitie].ve = -1;
					}
				}
			}
		}
		//Calculeaza valorile normale si in regim de blocaj
		for (int nivel = 0; nivel < MAX_X; nivel++) {
			for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
				if (SLC[nivel][pozitie].tipP != '\0') {
					SLC[nivel][pozitie].vn = calculeazaValoarePoarta(nivel, pozitie);
					if (SLC[nivel][pozitie].stare == 1) {

						SLC[nivel][pozitie].ve = SLC[nivel][pozitie].b;
					}
					else {
						SLC[nivel][pozitie].ve = calculeazaValoareEronata(nivel, pozitie);
					}
				}
			}
		}
		//Face propagarea defectelor intrarilor pe circuit
		for (int nivel = 0; nivel < MAX_X; nivel++) {
			for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
				if (SLC[nivel][pozitie].tipP != '\0') {
					propagaDefecte(nivel, pozitie);
				}
			}
		}
		//Continua propagarea defectelor pana nu mai apar modificari sau s-a atins numarul maxim de iteratii (un mecanism de recursivitate)
		bool schimbare = false;
		int maxIterations = 10;
		int iterations = 0;
		do {
			schimbare = false;
			iterations++;
			for (int nivel = 0; nivel < MAX_X; nivel++) {
				for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
					if (SLC[nivel][pozitie].tipP != '\0' && SLC[nivel][pozitie].tipP != 'I') {
						//Fac o copie a defectelor curente
						int* defecteVechi = new int[2 * nrDefecte];
						if (SLC[nivel][pozitie].defecte != nullptr) {
							memcpy(defecteVechi, SLC[nivel][pozitie].defecte, sizeof(int) * 2 * nrDefecte);
						}
						//Rulez iar
						propagaDefecte(nivel, pozitie);
						//Verific daca am o modificare fata de defectele anterioare
						if (SLC[nivel][pozitie].defecte != nullptr) {
							for (int i = 0; i < 2 * nrDefecte; i++) {
								if (SLC[nivel][pozitie].defecte[i] != defecteVechi[i]) {
									schimbare = true;
									break;
								}
							}
						}
						//Eliberez memorie temporara
						delete[] defecteVechi;
						if (schimbare) break; //Oprire timpurie daca s-a produs schimbare
					}
				}
				if (schimbare) break;
			}
		} while (schimbare && iterations < maxIterations);
		//Opresc cronometrul si afisez cat a durat executia in milisecunde
		timer->Stop();
		TimeBox->Text = "Time Simulation: " + timer->ElapsedMilliseconds.ToString() + " ms";
		//Daca au fost mai multe iteratii, afisez si numarul acestora
		if (iterations > 1) {
			TimeBox->Text += " (Iterations: " + iterations.ToString() + ")";
		}
	}
	/// <summary>
	/// Functie pentru generarea raportului "Generate Raport"
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void generateRaportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "Text Files (*.txt)|*.txt";
		saveFileDialog->DefaultExt = "txt";

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ raportFilePath = saveFileDialog->FileName;
			if (File::Exists(raportFilePath)) {
				File::Delete(raportFilePath);
			}

			Dictionary<wchar_t, String^>^ tipPoartaMap = gcnew Dictionary<wchar_t, String^>();
			tipPoartaMap->Add(L'a', "AND");
			tipPoartaMap->Add(L'o', "OR");
			tipPoartaMap->Add(L'N', "NOT");
			tipPoartaMap->Add(L'x', "XOR");
			tipPoartaMap->Add(L'A', "NAND");
			tipPoartaMap->Add(L'O', "NOR");
			tipPoartaMap->Add(L'I', "IN");
			tipPoartaMap->Add(L'B', "BUFFER");
			tipPoartaMap->Add(L'X', "XNOR");


			array<Tuple<int, int>^>^ defectToGate = gcnew array<Tuple<int, int>^>(nrDefecte);
			int gateIndex = 0;
			for (int nivel = 0; nivel < MAX_X; nivel++) {
				for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
					if (SLC[nivel][pozitie].tipP != '\0') {
						defectToGate[gateIndex] = gcnew Tuple<int, int>(nivel, pozitie);
						gateIndex++;
					}
				}
			}

			StreamWriter^ writer = gcnew StreamWriter(raportFilePath);
			writer->WriteLine("Raport Simulare");
			writer->WriteLine("Nivel | Pozitie | Tip Poarta | Valoare Iesire (vn) | Valoare Eronata (ve) | Propagare Defecte");
			writer->WriteLine("----------------------------------------------------------------------------------------------");

			for (int nivel = 0; nivel < MAX_X; nivel++) {
				for (int pozitie = 0; pozitie < MAX_Y; pozitie++) {
					if (SLC[nivel][pozitie].tipP != '\0') {
						String^ tipPoarta = tipPoartaMap->ContainsKey(SLC[nivel][pozitie].tipP) ?
							tipPoartaMap[SLC[nivel][pozitie].tipP] : "Necunoscut";
						String^ valoareVN = (SLC[nivel][pozitie].vn == -1) ? "nedefinit" : SLC[nivel][pozitie].vn.ToString();
						String^ valoareVE = (SLC[nivel][pozitie].ve == -1) ? "nedefinit" : SLC[nivel][pozitie].ve.ToString();

						List<String^>^ pozitiiDefecte = gcnew List<String^>();


						for (int i = 0; i < 2 * nrDefecte; i++) {
							if (SLC[nivel][pozitie].defecte != nullptr && SLC[nivel][pozitie].defecte[i] == 1) {
								int defectGateIndex = i / 2;
								int defectType = i % 2;


								if (defectGateIndex < nrDefecte && defectToGate[defectGateIndex] != nullptr) {
									int defNiv = defectToGate[defectGateIndex]->Item1;
									int defPoz = defectToGate[defectGateIndex]->Item2;

									String^ defect = String::Format("({0},{1})b{2}", defNiv, defPoz, defectType);
									pozitiiDefecte->Add(defect);
								}
							}
						}

						String^ mesajDefecte = pozitiiDefecte->Count > 0
							? String::Join(", ", pozitiiDefecte)
							: "-";

						writer->WriteLine("{0,-6} | {1,-8} | {2,-10} | {3,-18} | {4,-18} | {5}",
							SLC[nivel][pozitie].niv,
							SLC[nivel][pozitie].poz,
							tipPoarta,
							valoareVN,
							valoareVE,
							mesajDefecte);
					}
				}
			}
			writer->Close();
		}
	}

	private: System::Void addTestVectorFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void saveRaportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void saveTestVectorsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	/// <summary>
	/// Functia pentru Help
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(
			"Program pentru testarea circuitelor logice combinationale\n\n"
			"Acest program permite incarcarea unui fisier de descriere a circuitului, "
			"simularea functionarii, detectare vectori de test pentru un blocaj anume, "
			"si o simulare clasica, exhaustiva pentru analiza fiecarei porti logice. \n\n"
			"Instructiuni: \n"
			"- Deschideti un fisier de descriere valid (.dfs). File -> Add File\n"
			"- Run Simulation, dupa care Raport -> Generate Raport/Generate Truth Table/Classic Simulation\n"
			"Generate Raport - genereaza raportul circuitului\n"
			"Generate Truth Table - genereaza tabelul de adevar a circuitului(in cazul in care este atribuit un blocaj pe o poarta)\n"
			"Classic Simulation - simulare clasica\n"
			"Legenda porti logice : a - AND, o - OR, N - NOT, B - BUFFER, A - NAND, O - NOR, x - XOR, X - NXOR\n"
			"Autor: Nicodei Radu-George\n"
			"Versiune: 1.0",
			"Despre program",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	}
	/// <summary>
	/// Functia Exit
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	/// <summary>
	/// Functie pentru generarea tabelului de adevar
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void generateTruthTableToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "Text Files (*.txt)|*.txt";
		saveFileDialog->DefaultExt = "txt";
		saveFileDialog->Title = "Salveaza tabela de adevar";

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ raportFilePath = saveFileDialog->FileName;
			if (File::Exists(raportFilePath)) {
				File::Delete(raportFilePath);
			}

			StreamWriter^ writer = gcnew StreamWriter(raportFilePath);
			//Scrie antetul tabelei
			String^ header = "Intrari |";
			for (int i = 0; i < nrIesiri; i++) {
				header += String::Format(" z{0}n | z{0}e |", i + 1);
			}
			header += "VT";
			writer->WriteLine(header);

			//Scrie o linie de separare
			String^ separator = gcnew String(L'-', header->Length);
			writer->WriteLine(separator);

			List<String^>^ testVectors = gcnew List<String^>();

			determinaIesiriLaNivelMax(iesiriX, iesiriY, nrIesiri);

			//Creez lista cu pozitiile intrarilor din circuit
			List<Point>^ inputPoz = gcnew List<Point>();
			for (int i = 0; i < MAX_X; i++) {
				for (int j = 0; j < MAX_Y; j++) {
					if (SLC[i][j].tipP == 'I') {
						inputPoz->Add(Point(i, j));
					}
				}
			}

			int numInputs = inputPoz->Count;
			int numCombinations = (1 << numInputs); // 2^n combinatii posibile

			//Pentru fiecare combinatie binara posibila, resetez valorile normale/eronata ale portilor
			for (int comb = 0; comb < numCombinations; comb++) {
				for (int i = 0; i < MAX_X; i++) {
					for (int j = 0; j < MAX_Y; j++) {
						SLC[i][j].vn = -1;
						if (SLC[i][j].stare != 1) {
							SLC[i][j].ve = -1;
						}
					}
				}
				String^ binInputs = "";
				for (int i = 0; i < numInputs; i++) {
					/*
					* comb este un intreg care reprezinta o combinatie binara (ex. 5->101)
					* se face >> (numInputs - 1 - i) pentru a aduce bitul de interes pe pozitia 0.
					* se aplica & 1 pentru a extrage doar acel bit
					*/
					int bit = (comb >> (numInputs - 1 - i)) & 1;
					SLC[inputPoz[i].X][inputPoz[i].Y].vn = bit;
					SLC[inputPoz[i].X][inputPoz[i].Y].ve = bit;
					binInputs += bit.ToString();
				}

				String^ iesiriOutput = String::Format("{0,-6} |", binInputs);
				bool testFailed = false;

				//Evaluez fiecare iesire: normal si eronat
				for (int i = 0; i < nrIesiri; i++) {
					int x = iesiriX[i];
					int y = iesiriY[i];

					int vn = evalueazaPoarta(x, y);
					int ve = (SLC[x][y].stare == 1) ? SLC[x][y].b : evalueazaPoartaEronata(x, y);

					iesiriOutput += String::Format("  {0}  |  {1}  |", vn, ve);
					if (vn != ve) testFailed = true;
				}
				//Marchez daca este vector de test (✓) sau nu (-)
				String^ testVector = testFailed ? u8"\u2713" : "-";
				iesiriOutput += " " + testVector;
				writer->WriteLine(iesiriOutput);

				if (testFailed) {
					testVectors->Add(binInputs);
				}
			}
			writer->WriteLine("\nVectori de Test (VT):");
			for (int i = 0; i < testVectors->Count; i++) {
				writer->WriteLine("VT " + (i + 1) + ": " + testVectors[i]);
			}
			writer->Close();
		}
	}
	/// <summary>
	/// Functie pentru generarea raportului pentru simularea clasica
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void classicSimulationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
		saveDialog->Filter = "Text Files (*.txt)|*.txt";
		saveDialog->Title = "Salveaza raportul cu defectele detectate";

		if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ path = saveDialog->FileName;
			StreamWriter^ writer = gcnew StreamWriter(path);
			Dictionary<wchar_t, String^>^ tipPoartaMap = gcnew Dictionary<wchar_t, String^>();
			tipPoartaMap->Add(L'a', "AND");
			tipPoartaMap->Add(L'o', "OR");
			tipPoartaMap->Add(L'N', "NOT");
			tipPoartaMap->Add(L'x', "XOR");
			tipPoartaMap->Add(L'A', "NAND");
			tipPoartaMap->Add(L'O', "NOR");
			tipPoartaMap->Add(L'I', "IN");
			tipPoartaMap->Add(L'B', "BUFFER");
			tipPoartaMap->Add(L'X', "XNOR");

			writer->WriteLine("Raport detectie defecte clasica:");
			writer->WriteLine("-------------------------------");

			determinaIesiriLaNivelMax(iesiriX, iesiriY, nrIesiri);
			//aici se aplica aceeasi logica ca de la functia pentru generarea tabelului de adevar
			List<Point>^ inputPoz = gcnew List<Point>();
			for (int i = 0; i < MAX_X; i++) {
				for (int j = 0; j < MAX_Y; j++) {
					if (SLC[i][j].tipP == 'I') {
						inputPoz->Add(Point(i, j));
					}
				}
			}

			int numInputs = inputPoz->Count;
			int numCombinations = (1 << numInputs);

			for (int x = 0; x < MAX_X; x++) {
				for (int y = 0; y < MAX_Y; y++) {
					if (SLC[x][y].tipP != '\0') {
						wchar_t tip = SLC[x][y].tipP;
						String^ tipPoarta = tipPoartaMap->ContainsKey(tip) ? tipPoartaMap[tip] : tip.ToString();
						writer->WriteLine(String::Format(">> Testez poarta la ({0},{1}), tip '{2}'", x, y, tipPoarta));
						for (int b = 0; b <= 1; b++) {
							SLC[x][y].stare = 1;
							SLC[x][y].b = b;
							writer->WriteLine(String::Format("  >> Defect b{0}:", b));
							for (int comb = 0; comb < numCombinations; comb++) {
								for (int i = 0; i < MAX_X; i++) {
									for (int j = 0; j < MAX_Y; j++) {
										SLC[i][j].vn = -1;
										SLC[i][j].ve = -1;
									}
								}
								String^ vt = "";
								for (int i = 0; i < numInputs; i++) {
									int bit = (comb >> (numInputs - 1 - i)) & 1;
									SLC[inputPoz[i].X][inputPoz[i].Y].vn = bit;
									SLC[inputPoz[i].X][inputPoz[i].Y].ve = bit;
									vt += bit.ToString();
								}

								List<String^>^ listaDefecte = gcnew List<String^>();
								for (int i = 0; i < MAX_X; i++) {
									for (int j = 0; j < MAX_Y; j++) {
										if (SLC[i][j].tipP != '\0') {
											int vn = evalueazaPoarta(i, j);
											int ve = evalueazaPoartaEronata(i, j);

											if (vn != ve && vn != -1 && ve != -1) {
												String^ defect = String::Format("({0},{1})b{2}", i, j, ve);
												if (!listaDefecte->Contains(defect)) {
													listaDefecte->Add(defect);
												}
											}
										}
									}
								}
								writer->Write(String::Format("    >> X = {0} : ", vt));
								if (listaDefecte->Count > 0) {
									for (int i = 0; i < listaDefecte->Count; i++) {
										writer->Write(listaDefecte[i]);
										if (i < listaDefecte->Count - 1)
											writer->Write(" ");
									}
								}
								else {
									writer->Write("-");
								}
								writer->WriteLine();
							}
							SLC[x][y].stare = 0;
						}
					}
				}
			}
			writer->WriteLine("\n-------------------------------");
			writer->WriteLine(">> Simulare clasica finalizata.");
			writer->Close();
		}
	}
	/// <summary>
	/// Functie event pentru resetare valori (pentru a nu mai da de fiecare data Add File si sa imi generez raport)
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void resetToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		resetValues();
	}
};
};