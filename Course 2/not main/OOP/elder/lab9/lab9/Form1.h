#pragma once

#include <string.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0400
#include "windows.h"
#include <stdio.h>
#include <iostream>

namespace lab9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void) {InitializeComponent();}
	protected:
		~Form1(){if (components) delete components;	}
	private: System::Windows::Forms::Button^  ButtonBuilder;
	private: System::Windows::Forms::Button^  ButtonHelp;
	private: System::Windows::Forms::Button^  ButtonColor;
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private:
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
			 Color oldColor; // ��� ����������� ������� �����

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)	{
			this->ButtonBuilder = (gcnew System::Windows::Forms::Button());
			this->ButtonHelp = (gcnew System::Windows::Forms::Button());
			this->ButtonColor = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ButtonBuilder
			// 
			this->ButtonBuilder->Location = System::Drawing::Point(12, 38);
			this->ButtonBuilder->Name = L"ButtonBuilder";
			this->ButtonBuilder->Size = System::Drawing::Size(75, 23);
			this->ButtonBuilder->TabIndex = 0;
			this->ButtonBuilder->Text = L"ButtonBuilder";
			this->ButtonBuilder->UseVisualStyleBackColor = true;
			this->ButtonBuilder->Click += gcnew System::EventHandler(this, &Form1::ButtonBuilder_Click);
			this->ButtonBuilder->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::ButtonBuilder_KeyPress);
			// 
			// ButtonHelp
			// 
			this->ButtonHelp->Location = System::Drawing::Point(12, 67);
			this->ButtonHelp->Name = L"ButtonHelp";
			this->ButtonHelp->Size = System::Drawing::Size(75, 23);
			this->ButtonHelp->TabIndex = 1;
			this->ButtonHelp->Text = L"ButtonHelp";
			this->ButtonHelp->UseVisualStyleBackColor = true;
			this->ButtonHelp->Click += gcnew System::EventHandler(this, &Form1::ButtonHelp_Click);
			// 
			// ButtonColor
			// 
			this->ButtonColor->Location = System::Drawing::Point(12, 96);
			this->ButtonColor->Name = L"ButtonColor";
			this->ButtonColor->Size = System::Drawing::Size(75, 23);
			this->ButtonColor->TabIndex = 2;
			this->ButtonColor->Text = L"ButtonColor";
			this->ButtonColor->UseVisualStyleBackColor = true;
			this->ButtonColor->Click += gcnew System::EventHandler(this, &Form1::ButtonColor_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Exit\?";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(100, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(163, 20);
			this->textBox1->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 166);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ButtonColor);
			this->Controls->Add(this->ButtonHelp);
			this->Controls->Add(this->ButtonBuilder);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDoubleClick);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		char* SystemStringToChar(System::String^ string) 
		{
            return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(string);
        }
		System::String^ CharToSystemString(char* ch) 
		{
			return gcnew String(ch);
		}
#pragma endregion

//

	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) { // ���������� �������� �����
				FILE *file; // ����
				String ^ filename = System::Diagnostics::Process::GetCurrentProcess()->ProcessName+".ini"; // ��� �������� ��������, ��� ������� �����
				file = fopen(SystemStringToChar(filename),"w"); // �������� ���� � ������ filename ��� ������
				fputs(SystemStringToChar(""+this->Top),file); // ������� ������� ���������� �����
				fputc('\n',file); // ������� �� ����� ������
				fputs(SystemStringToChar(""+this->Left),file); // ����� �������
				fputc('\n',file);
				fputs(SystemStringToChar(""+this->Width),file); // ������
				fputc('\n',file);
				fputs(SystemStringToChar(""+this->Height),file); // ������
				if(textBox1->Text != "") // ���� ��������� �� ������
				{
					fputc('\n',file); // �� ����� ������
					fputs(SystemStringToChar(this->textBox1->Text),file); // ������� ���� �����
				}
				fclose(file); // ��������� ����

			 }
	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) { // ���������� �������� �����
				char buff[100];
				String ^ filename = System::Diagnostics::Process::GetCurrentProcess()->ProcessName+".ini"; // ������ ��� �����
				{
					FILE *file;
					file = fopen(SystemStringToChar(filename),"r"); // ��������� ���� ��� ������
					if(file != NULL) // ���� �� ����������
					{
						int a;

						fscanf(file,"%d",&a); // ��������� ������ �����
						this->Top = a; // ������ ������� ���������� �����
							
						fscanf(file,"%d",&a); // ������ �����
						this->Left = a; // ����� ����������
							
						fscanf(file,"%d",&a);
						this->Width = a; // ������ �����
							
						fscanf(file,"%d",&a);
						this->Height = a; // ������
						int i = 0;
						while(!feof(file)) // ���� �� ����� �����
						{
							buff[i++] = fgetc(file); // ��������� ������ � ����
						}
						buff[i > 0 ? --i:i] = '\0';// ������������ ������ ������� �������� (��������� ����� ������)
						this->textBox1->Text = CharToSystemString(buff); // ������ ���� ����� ����������
						fclose(file); // ��������� ����
					}
				}
			 }
	private: System::Void ButtonBuilder_Click(System::Object^  sender, System::EventArgs^  e) { // buttonBuilde
				System::Windows::Forms::DialogResult res; // ������� ������ ���� DialogResult
				res=MessageBox::Show("message!", "Form NEVER Closing", MessageBoxButtons::YesNo,MessageBoxIcon::Question); // ������ ���� ������������ �� ��� ���.

				if (res == System::Windows::Forms::DialogResult::No) // ���� ������� ���
				{
					label1->Text=L"You chose No"; // ������� ��� ������� ���
				}
				else
				{
					label1->Text=L"You chose Yes"; // ����� ������� ��
				}
			 }
	private: System::Void ButtonBuilder_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { // ������� ������
				if (e->KeyChar == (wchar_t)Keys::Escape) // ���� ������ ������
				 {
					 label1->Text = ""; // ������� �����
				 }
			 }
private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { // ���� ����� �� �����
			 this->Text = L"��� ���"; // ������ ��������� �����
		 }
private: System::Void Form1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { // ������� ���� �� �����
			  this->Text = L"� ��� ������"; // ������ ��������� �����
		 }
private: System::Void ButtonHelp_Click(System::Object^  sender, System::EventArgs^  e) { // buttonHelp
			 MessageBox::Show(this,"������ �� ����!","Help",MessageBoxButtons::OK,MessageBoxIcon::Question); // ����� ���������
		 }
private: System::Void ButtonColor_Click(System::Object^  sender, System::EventArgs^  e) { // buttonColor
			 System::Windows::Forms::DialogResult res;
				res=MessageBox::Show("��������� � ������� ����?", "��������", MessageBoxButtons::YesNo,MessageBoxIcon::Question); // ���������� ����������� ��� ���?

				if (res == System::Windows::Forms::DialogResult::No) // ���� ���
				{
					this->BackColor = oldColor; // ����������� � ������ ����
				}
				else
				{
					this->BackColor = Color::Green; // ����� � �������
				}
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) { // �������� �����
			 	System::Windows::Forms::DialogResult res;
				res=MessageBox::Show("�������?", "Form Closing", MessageBoxButtons::YesNo,MessageBoxIcon::Question); // ������� �� �����?

				if (res == System::Windows::Forms::DialogResult::No) // ���� ���
				{
					label1->Text = e->CloseReason.ToString(); // �������  � ����� ������� ����������
					e->Cancel = true; // �������� ��������
					
				}
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { // ��� ��� �������� Exit?
			 this->Close(); // �����
		 }
	};
}

