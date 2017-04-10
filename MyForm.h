#pragma once
#include "Zveno.h"
#include "Spisok.h"
#include "Polinom.h"

namespace Проект2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  textBox4;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(229, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 124);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(229, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 197);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(229, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Visible = false;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(152, 12);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 3;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(152, 38);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 4;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Accept";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(71, 38);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Change";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(247, 76);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(38, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"ok";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(247, 121);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(38, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"ok";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 158);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 9;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(93, 158);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 10;
			this->button6->Text = L"-";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(174, 158);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 11;
			this->button7->Text = L"*";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(255, 158);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 23);
			this->button8->TabIndex = 12;
			this->button8->Text = L"*";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(291, 158);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(35, 20);
			this->textBox4->TabIndex = 13;
			this->textBox4->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(349, 261);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int maxst;
		int n;
		void MarshalString ( String ^ s, string& os ) {  
   using namespace Runtime::InteropServices;  
   const char* chars =   
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
   os = chars;  
   Marshal::FreeHGlobal(IntPtr((void*)chars));   
}  
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 maxst=Convert::ToInt32(numericUpDown1->Value);
				 n=Convert::ToInt32(numericUpDown2->Value);
				 numericUpDown1->Increment=0;
				 numericUpDown2->Increment=0;
				 textBox1->Visible=true;
				 textBox2->Visible=true;
				 button3->Visible=true;
				 button4->Visible=true;
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ strs=textBox1->Text;
			 std::string str;
			 MarshalString(strs,str);
			 Polinom frs(maxst,n,str);
			 str=frs.GetString();
			 if(str[0]=='+')
				 str.erase(0,1);
			 if((str.find("+0")>0)&&((str.find("+0")<str.length())))
				 str.erase(str.length()-3,3);
			 strs=gcnew String(str.c_str());
			 textBox1->Text=strs;

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ strs=textBox2->Text;
			 std::string str;
			 MarshalString(strs,str);
			 Polinom frs(maxst,n,str);
			 str=frs.GetString();
			 if(str[0]=='+')
				 str.erase(0,1);
			 strs=gcnew String(str.c_str());
			 textBox2->Text=strs;
			 textBox3->Visible=true;
			 textBox4->Visible=true;
			 button5->Visible=true;
			 button6->Visible=true;
			 button7->Visible=true;
			 button8->Visible=true;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ strf=textBox1->Text;
			 System::String^ strs=textBox2->Text;
			 string ft;
			 string st;
			 MarshalString(strf,ft);
			 MarshalString(strs,st);
			 Polinom frs(maxst,n,ft);
			 Polinom sec(maxst,n,st);
			 frs =frs+sec;
			 string res=frs.GetString();
			  if(res[0]=='+')
				 res.erase(0,1);
			 String^ str2 = gcnew String(res.c_str()); 
			 textBox3->Text=str2;
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ strf=textBox1->Text;
			 System::String^ strs=textBox2->Text;
			 string ft;
			 string st;
			 MarshalString(strf,ft);
			 MarshalString(strs,st);
			 Polinom frs(maxst,n,ft);
			 Polinom sec(maxst,n,st);
			 frs =sec-frs;
			 string res=frs.GetString();
			 if(res[0]=='+')
				 res.erase(0,1);
			 String^ str2 = gcnew String(res.c_str()); 
			 textBox3->Text=str2;
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ strf=textBox1->Text;
			 System::String^ strs=textBox2->Text;
			 string ft;
			 string st;
			 MarshalString(strf,ft);
			 MarshalString(strs,st);
			 Polinom frs(maxst,n,ft);
			 Polinom sec(maxst,n,st);
			 frs=frs*sec;
			 string res=frs.GetString();
			  if(res[0]=='+')
				 res.erase(0,1);
			 String^ str2 = gcnew String(res.c_str()); 
			 textBox3->Text=str2;
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ strf=textBox1->Text;
			 string ft;
			 MarshalString(strf,ft);
			 Polinom frs(maxst,n,ft);
			 int n=Convert::ToInt32(textBox4->Text);
			 frs=frs*n;
			 string res=frs.GetString();
			  if(res[0]=='+')
				 res.erase(0,1);
			 String^ str2 = gcnew String(res.c_str()); 
			 textBox3->Text=str2;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox3->Visible=false;
			 textBox4->Visible=false;
			 button5->Visible=false;
			 button6->Visible=false;
			 button7->Visible=false;
			 button8->Visible=false;
			 textBox3->Visible=false;
			 textBox3->Visible=false;
			 numericUpDown1->Increment=1;
			 numericUpDown2->Increment=1;
		 }
};
}
