#pragma once

namespace WorkersManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	public ref class Program : public System::Windows::Forms::Form
	{
	public:
		int id_uzytkownika;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ txtPLogin;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtPNazwisko;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtPImie;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::CheckBox^ chbPPracownik;

	private: System::Windows::Forms::Button^ btnPSzukaj;
	private: System::Windows::Forms::TextBox^ txtPSzukaj;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dgUzytkownicy;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ txtHNowe1;
	private: System::Windows::Forms::Button^ btnHZmien;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtHNowe2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtHStare;
	private: System::Windows::Forms::Button^ btnPDodaj;
	private: System::Windows::Forms::Button^ btnPModyfikuj;
	private: System::Windows::Forms::Button^ btnPUsun;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtPNumertelefonu;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtpadres;
	private: System::Windows::Forms::TextBox^ txtPdatarej;
	private: System::Windows::Forms::TextBox^ txtpRola;
	public:
		String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=YES;database=relacja";
		Program(int uzytkownik)
		{
			InitializeComponent();
			id_uzytkownika = uzytkownik;
		}
	protected:
		~Program()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btnPDodaj = (gcnew System::Windows::Forms::Button());
			this->btnPModyfikuj = (gcnew System::Windows::Forms::Button());
			this->btnPUsun = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtpadres = (gcnew System::Windows::Forms::TextBox());
			this->txtPdatarej = (gcnew System::Windows::Forms::TextBox());
			this->txtpRola = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtPNumertelefonu = (gcnew System::Windows::Forms::TextBox());
			this->txtPLogin = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtPNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtPImie = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->chbPPracownik = (gcnew System::Windows::Forms::CheckBox());
			this->btnPSzukaj = (gcnew System::Windows::Forms::Button());
			this->txtPSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dgUzytkownicy = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtHNowe1 = (gcnew System::Windows::Forms::TextBox());
			this->btnHZmien = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtHNowe2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtHStare = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUzytkownicy))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1065, 495);
			this->tabControl1->TabIndex = 0;
			this->tabPage2->Controls->Add(this->btnPDodaj);
			this->tabPage2->Controls->Add(this->btnPModyfikuj);
			this->tabPage2->Controls->Add(this->btnPUsun);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->btnPSzukaj);
			this->tabPage2->Controls->Add(this->txtPSzukaj);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->dgUzytkownicy);
			this->tabPage2->Location = System::Drawing::Point(4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1057, 469);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Uzytkownicy";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->btnPDodaj->Location = System::Drawing::Point(950, 369);
			this->btnPDodaj->Name = L"btnPDodaj";
			this->btnPDodaj->Size = System::Drawing::Size(75, 23);
			this->btnPDodaj->TabIndex = 1;
			this->btnPDodaj->Text = L"dodaj";
			this->btnPDodaj->UseVisualStyleBackColor = true;
			this->btnPDodaj->Click += gcnew System::EventHandler(this, &Program::btnPDodaj_Click);
			this->btnPModyfikuj->Location = System::Drawing::Point(950, 428);
			this->btnPModyfikuj->Name = L"btnPModyfikuj";
			this->btnPModyfikuj->Size = System::Drawing::Size(75, 23);
			this->btnPModyfikuj->TabIndex = 2;
			this->btnPModyfikuj->Text = L"modyfikuj";
			this->btnPModyfikuj->UseVisualStyleBackColor = true;
			this->btnPModyfikuj->Click += gcnew System::EventHandler(this, &Program::btnPModyfikuj_Click);
			this->btnPUsun->Location = System::Drawing::Point(950, 398);
			this->btnPUsun->Name = L"btnPUsun";
			this->btnPUsun->Size = System::Drawing::Size(75, 23);
			this->btnPUsun->TabIndex = 3;
			this->btnPUsun->Text = L"usuñ";
			this->btnPUsun->UseVisualStyleBackColor = true;
			this->btnPUsun->Click += gcnew System::EventHandler(this, &Program::btnPUsun_Click);
			this->groupBox2->Controls->Add(this->txtpadres);
			this->groupBox2->Controls->Add(this->txtPdatarej);
			this->groupBox2->Controls->Add(this->txtpRola);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->txtPNumertelefonu);
			this->groupBox2->Controls->Add(this->txtPLogin);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->txtPNazwisko);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->txtPImie);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->chbPPracownik);
			this->groupBox2->Location = System::Drawing::Point(11, 359);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(933, 92);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Edycja danych u¿ytkownika";
			this->txtpadres->Location = System::Drawing::Point(682, 60);
			this->txtpadres->Name = L"txtpadres";
			this->txtpadres->Size = System::Drawing::Size(171, 20);
			this->txtpadres->TabIndex = 14; 
			this->txtPdatarej->Location = System::Drawing::Point(602, 60);
			this->txtPdatarej->Name = L"txtPdatarej";
			this->txtPdatarej->Size = System::Drawing::Size(74, 20);
			this->txtPdatarej->TabIndex = 13;
			this->txtPdatarej->TextChanged += gcnew System::EventHandler(this, &Program::txtPdatarej_TextChanged); 
			this->txtpRola->Location = System::Drawing::Point(465, 60);
			this->txtpRola->Name = L"txtpRola";
			this->txtpRola->Size = System::Drawing::Size(131, 20);
			this->txtpRola->TabIndex = 12;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(679, 44);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(34, 13);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Adres";
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(599, 44);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 13);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Data rejestracji";
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(462, 44);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(29, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Rola";
			this->label9->Click += gcnew System::EventHandler(this, &Program::label9_Click);
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(356, 44);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Numer telefonu";
			this->label8->Click += gcnew System::EventHandler(this, &Program::label8_Click);
			this->txtPNumertelefonu->Location = System::Drawing::Point(359, 60);
			this->txtPNumertelefonu->Name = L"txtPNumertelefonu";
			this->txtPNumertelefonu->Size = System::Drawing::Size(100, 20);
			this->txtPNumertelefonu->TabIndex = 7;
			this->txtPLogin->Location = System::Drawing::Point(218, 60);
			this->txtPLogin->Name = L"txtPLogin";
			this->txtPLogin->Size = System::Drawing::Size(135, 20);
			this->txtPLogin->TabIndex = 6;
			this->txtPLogin->TextChanged += gcnew System::EventHandler(this, &Program::txtPLogin_TextChanged);
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(215, 44);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(36, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Login:";
			this->txtPNazwisko->Location = System::Drawing::Point(113, 60);
			this->txtPNazwisko->Name = L"txtPNazwisko";
			this->txtPNazwisko->Size = System::Drawing::Size(100, 20);
			this->txtPNazwisko->TabIndex = 4;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(110, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Nazwisko:"; 
			this->txtPImie->Location = System::Drawing::Point(6, 60);
			this->txtPImie->Name = L"txtPImie";
			this->txtPImie->Size = System::Drawing::Size(100, 20);
			this->txtPImie->TabIndex = 2;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Imiê:";
			this->chbPPracownik->AutoSize = true;
			this->chbPPracownik->Location = System::Drawing::Point(6, 24);
			this->chbPPracownik->Name = L"chbPPracownik";
			this->chbPPracownik->Size = System::Drawing::Size(81, 17);
			this->chbPPracownik->TabIndex = 0;
			this->chbPPracownik->Text = L"Uzytkownik";
			this->chbPPracownik->UseVisualStyleBackColor = true;
			this->btnPSzukaj->Location = System::Drawing::Point(280, 10);
			this->btnPSzukaj->Name = L"btnPSzukaj";
			this->btnPSzukaj->Size = System::Drawing::Size(75, 23);
			this->btnPSzukaj->TabIndex = 3;
			this->btnPSzukaj->Text = L"szukaj";
			this->btnPSzukaj->UseVisualStyleBackColor = true;
			this->btnPSzukaj->Click += gcnew System::EventHandler(this, &Program::btnPSzukaj_Click);
			this->txtPSzukaj->Location = System::Drawing::Point(78, 12);
			this->txtPSzukaj->Name = L"txtPSzukaj";
			this->txtPSzukaj->Size = System::Drawing::Size(196, 20);
			this->txtPSzukaj->TabIndex = 2;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Uzytkownik";
			this->dgUzytkownicy->AllowUserToAddRows = false;
			this->dgUzytkownicy->AllowUserToOrderColumns = true;
			this->dgUzytkownicy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgUzytkownicy->Location = System::Drawing::Point(11, 39);
			this->dgUzytkownicy->Name = L"dgUzytkownicy";
			this->dgUzytkownicy->Size = System::Drawing::Size(1040, 314);
			this->dgUzytkownicy->TabIndex = 0;
			this->dgUzytkownicy->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Program::dgUzytkownicy_CellClick);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1057, 469);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Zmiana has³a";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->groupBox1->Controls->Add(this->txtHNowe1);
			this->groupBox1->Controls->Add(this->btnHZmien);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->txtHNowe2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->txtHStare);
			this->groupBox1->Location = System::Drawing::Point(217, 73);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(249, 169);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zmiana has³a";
			this->txtHNowe1->Location = System::Drawing::Point(98, 68);
			this->txtHNowe1->Name = L"txtHNowe1";
			this->txtHNowe1->Size = System::Drawing::Size(100, 20);
			this->txtHNowe1->TabIndex = 4;
			this->txtHNowe1->TextChanged += gcnew System::EventHandler(this, &Program::txtHNowe1_TextChanged);
			this->btnHZmien->Enabled = false;
			this->btnHZmien->Location = System::Drawing::Point(98, 140);
			this->btnHZmien->Name = L"btnHZmien";
			this->btnHZmien->Size = System::Drawing::Size(75, 23);
			this->btnHZmien->TabIndex = 6;
			this->btnHZmien->Text = L"zmieñ";
			this->btnHZmien->UseVisualStyleBackColor = true;
			this->btnHZmien->Click += gcnew System::EventHandler(this, &Program::btnHZmien_Click); 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Stare has³o:";
			this->txtHNowe2->Location = System::Drawing::Point(98, 97);
			this->txtHNowe2->Name = L"txtHNowe2";
			this->txtHNowe2->Size = System::Drawing::Size(100, 20);
			this->txtHNowe2->TabIndex = 5;
			this->txtHNowe2->TextChanged += gcnew System::EventHandler(this, &Program::txtHNowe2_TextChanged);
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nowe has³o:";
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Powtórz has³o:";
			this->txtHStare->Location = System::Drawing::Point(98, 35);
			this->txtHStare->Name = L"txtHStare";
			this->txtHStare->Size = System::Drawing::Size(100, 20);
			this->txtHStare->TabIndex = 3;
			this->txtHStare->TextChanged += gcnew System::EventHandler(this, &Program::txtHStare_TextChanged);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1080, 513);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Program";
			this->Text = L"Program";
			this->Load += gcnew System::EventHandler(this, &Program::Program_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUzytkownicy))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		int id_rekordu; 
		int uzytkownik; 

	private: System::Void Program_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: Void btnHZmien_pokaz() {
		if (txtHStare->Text != "" && txtHNowe1->Text != "" && txtHNowe1->Text == txtHNowe2->Text) {
			btnHZmien->Enabled = true;
		}
		else {
			btnHZmien->Enabled = false;
		}

	}
	private: System::Void txtHStare_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		btnHZmien_pokaz();
	}

	private: System::Void txtHNowe1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		btnHZmien_pokaz();
	}

	private: System::Void txtHNowe2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		btnHZmien_pokaz();
	}

		   
//Zmiana has³a 
	private: System::Void btnHZmien_Click(System::Object^ sender, System::EventArgs^ e) {
		MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("UPDATE kartoteka_uzytkownikow SET haslo = PASSWORD('" + txtHNowe1->Text + "') WHERE id_uzytkownika = " + id_uzytkownika + " AND haslo = PASSWORD('" + txtHStare->Text + "');", laczBaze);
		try {
			laczBaze->Open();
			if (zapytanie->ExecuteNonQuery()) {
				MessageBox::Show("Zmieni³em has³o");
			}
			else {
				MessageBox::Show("Podane has³o jest niepoprawne");
			}
			laczBaze->Close();
		}
		catch (Exception^ komunikat) {
			MessageBox::Show(komunikat->Message);
		}
	}
//Siatka uzytkownikow
	private: Void pokaz_siatke() {
		MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT id_uzytkownika, imie, nazwisko, email AS login, numer_telefonu,adres, rola, data_rejestracji, uprawnienia_dostepu FROM kartoteka_uzytkownikow ORDER BY nazwisko;", laczBaze);
		try {
			laczBaze->Open();
			MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
			moja->SelectCommand = zapytanie;
			DataTable^ tabela = gcnew DataTable();
			moja->Fill(tabela);

			BindingSource^ zrodlo = gcnew BindingSource();
			zrodlo->DataSource = tabela;
			dgUzytkownicy->DataSource = zrodlo;
			laczBaze->Close();
		}
		catch (Exception^ komunikat) {
			MessageBox::Show(komunikat->Message);
		}
	}
//Obsluga przycisku szukaj
	private: System::Void btnPSzukaj_Click(System::Object^ sender, System::EventArgs^ e) {
		MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT id_uzytkownika, imie, nazwisko, email AS login,numer_telefonu , uprawnienia_dostepu, rola, data_rejestracji, adres FROM kartoteka_uzytkownikow WHERE CONCAT(imie, nazwisko, email, numer_telefonu, rola, adres, data_rejestracji) LIKE '%" + txtPSzukaj->Text + "%' ORDER BY nazwisko;", laczBaze);
		try {
			laczBaze->Open();
			MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
			moja->SelectCommand = zapytanie;
			DataTable^ tabela = gcnew DataTable();
			moja->Fill(tabela);

			BindingSource^ zrodlo = gcnew BindingSource();
			zrodlo->DataSource = tabela;
			dgUzytkownicy->DataSource = zrodlo;
			laczBaze->Close();
		}
		catch (Exception^ komunikat) {
			MessageBox::Show(komunikat->Message);
		}

		dgUzytkownicy->Columns[0]->Visible = false;
	}
//Wcisniecie uzytkownika na siatce
	private: System::Void dgUzytkownicy_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			id_rekordu = Convert::ToInt32(dgUzytkownicy->Rows[e->RowIndex]->Cells[0]->Value);
			txtPImie->Text = dgUzytkownicy->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
			txtPNazwisko->Text = dgUzytkownicy->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
			txtPLogin->Text = dgUzytkownicy->Rows[e->RowIndex]->Cells["login"]->Value->ToString();
			txtPNumertelefonu->Text = dgUzytkownicy->Rows[e->RowIndex]->Cells["numer_telefonu"]->Value->ToString();
			txtpRola->Text = dgUzytkownicy->Rows[e->RowIndex]->Cells["Rola"]->Value->ToString();
			txtPdatarej->Text = dgUzytkownicy->Rows[e->RowIndex]->Cells["Data_rejestracji"]->Value->ToString();
			txtpadres->Text = dgUzytkownicy->Rows[e->RowIndex]->Cells["Adres"]->Value->ToString();
			chbPPracownik->Checked = Convert::ToBoolean(dgUzytkownicy->Rows[e->RowIndex]->Cells["uprawnienia_dostepu"]->Value);
		}
	}
//Dodawanie uzytkownika
	private: System::Void btnPDodaj_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtPImie->Text->Length < 3 || txtPNazwisko->Text->Length < 4 || txtPLogin->Text->Length < 5) {
			MessageBox::Show("uzupe³nij dane!");
		}
		else {
			uzytkownik_typ();
			MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczBaze->CreateCommand();
			MySqlTransaction^ transakcja;
			laczBaze->Open();
			transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczBaze;

			polecenie->Transaction = transakcja;
			try {
				polecenie->CommandText = "INSERT INTO kartoteka_uzytkownikow SET imie='" + txtPImie->Text + "', nazwisko='" + txtPNazwisko->Text + "', email = '" + txtPLogin->Text + "', numer_telefonu='"+ txtPNumertelefonu->Text +"', haslo = PASSWORD('" + txtPLogin->Text + "'), uprawnienia_dostepu = " + uzytkownik + ", rola = '" + txtpRola->Text +"', adres = '" + txtpadres->Text +"', data_rejestracji = DATE('"+txtPdatarej->Text+"')";

				polecenie->ExecuteNonQuery();
				transakcja->Commit();
			}
			catch (Exception^ komunikat) {
				MessageBox::Show(komunikat->Message);
				transakcja->Rollback();
			}

			laczBaze->Close();

		}
		pokaz_siatke();
	}
	private: Void uzytkownik_typ() {
		if (chbPPracownik->Checked) {
			uzytkownik = 1;
		}
		else {
			uzytkownik = 0;
		}
	}
//modyfikacja danych uzytkownika

	private: System::Void btnPModyfikuj_Click(System::Object^ sender, System::EventArgs^ e) {

		if (txtPImie->Text->Length < 3 || txtPNazwisko->Text->Length < 4 || txtPLogin->Text->Length < 5) {
			MessageBox::Show("uzupe³nij dane!");
		}
		else {
			uzytkownik_typ();
			MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczBaze->CreateCommand();
			MySqlTransaction^ transakcja;
			laczBaze->Open();
			transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczBaze;

			polecenie->Transaction = transakcja;

			try {
				polecenie->CommandText = "UPDATE kartoteka_uzytkownikow SET imie='" + txtPImie->Text + "', nazwisko='" + txtPNazwisko->Text + "', email = '" + txtPLogin->Text + "',numer_telefonu = '" + txtPNumertelefonu->Text + "',rola = '"+ txtpRola->Text +"', adres = '"+ txtpadres->Text + "', data_rejestracji = DATE('"+txtPdatarej->Text +"'), uprawnienia_dostepu = " + uzytkownik + " WHERE id_uzytkownika = " + id_rekordu + "; ";
				polecenie->ExecuteNonQuery();
				transakcja->Commit();
			}
			catch (Exception^ komunikat) {
				MessageBox::Show(komunikat->Message);
				transakcja->Rollback();
			}
			laczBaze->Close();
		}
		pokaz_siatke();
	}
//przycisk usun
	private: System::Void btnPUsun_Click(System::Object^ sender, System::EventArgs^ e) {
		if (id_rekordu == 1) {
			MessageBox::Show("Nie mo¿na usun¹æ u¿ytkownika Admin");
		}
		else {
			uzytkownik_typ();
			MySqlConnection^ laczBaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczBaze->CreateCommand();
			MySqlTransaction^ transakcja;
			laczBaze->Open();
			transakcja = laczBaze->BeginTransaction(IsolationLevel::ReadCommitted);
			polecenie->Connection = laczBaze;
			polecenie->Transaction = transakcja;
			try {
				if (MessageBox::Show("Czy usun¹æ wybranego u¿ytkownika?", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					polecenie->CommandText = "DELETE FROM kartoteka_uzytkownikow WHERE id_uzytkownika = " + id_rekordu + "; ";
					polecenie->ExecuteNonQuery();
					transakcja->Commit();
					MessageBox::Show("U¿ytkownik zosta³ usuniêty");
				}
			}
			catch (Exception^ komunikat) {
				MessageBox::Show(komunikat->Message);
				transakcja->Rollback();
			}
			laczBaze->Close();
		}
		txtPImie->Text = "";
		txtPNazwisko->Text = "";
		txtPLogin->Text = "";
		chbPPracownik->Checked = false;
		pokaz_siatke();
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void txtPLogin_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtPdatarej_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
