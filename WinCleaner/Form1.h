#pragma once

#include <Windows.h>
#include <lmcons.h>
#include <string>
#include <vector>

namespace CleanupApp {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Runtime::InteropServices;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            SetFixedSize();
            SetModernUI();
            DisplayWelcomeMessage();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
    private: System::Windows::Forms::Button^ btnClean;
    private: System::Windows::Forms::Label^ lblWelcome;
    private: System::Windows::Forms::LinkLabel^ linkGithub;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
            this->btnClean = (gcnew System::Windows::Forms::Button());
            this->lblWelcome = (gcnew System::Windows::Forms::Label());
            this->linkGithub = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            // 
            // checkedListBox1
            // 
            this->checkedListBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->checkedListBox1->BackColor = System::Drawing::SystemColors::Window;
            this->checkedListBox1->CheckOnClick = true;
            this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->checkedListBox1->ForeColor = System::Drawing::SystemColors::MenuText;
            this->checkedListBox1->FormattingEnabled = true;
            this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
                L"Windows temp files", L"Windows prefetch files",
                    L"Windows update cleanup", L"App temp files", L"Chrome cookies", L"Opera GX cookies"
            });
            this->checkedListBox1->Location = System::Drawing::Point(12, 87);
            this->checkedListBox1->Name = L"checkedListBox1";
            this->checkedListBox1->SelectionMode = System::Windows::Forms::SelectionMode::None;
            this->checkedListBox1->Size = System::Drawing::Size(320, 109);
            this->checkedListBox1->TabIndex = 0;
            this->checkedListBox1->ThreeDCheckBoxes = true;
            this->checkedListBox1->Click += gcnew System::EventHandler(this, &Form1::checkedListBox1_Click);
            // 
            // btnClean
            // 
            this->btnClean->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
                static_cast<System::Int32>(static_cast<System::Byte>(167)));
            this->btnClean->FlatAppearance->BorderSize = 0;
            this->btnClean->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClean->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->btnClean->ForeColor = System::Drawing::Color::White;
            this->btnClean->Location = System::Drawing::Point(12, 212);
            this->btnClean->Name = L"btnClean";
            this->btnClean->Size = System::Drawing::Size(320, 36);
            this->btnClean->TabIndex = 1;
            this->btnClean->Text = L"Clean";
            this->btnClean->UseVisualStyleBackColor = false;
            this->btnClean->Click += gcnew System::EventHandler(this, &Form1::btnClean_Click);
            // 
            // lblWelcome
            // 
            this->lblWelcome->AutoSize = true;
            this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblWelcome->Location = System::Drawing::Point(12, 20);
            this->lblWelcome->Name = L"lblWelcome";
            this->lblWelcome->Size = System::Drawing::Size(0, 37);
            this->lblWelcome->TabIndex = 2;
            // 
            // linkGithub
            // 
            this->linkGithub->AutoSize = true;
            this->linkGithub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->linkGithub->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->linkGithub->Location = System::Drawing::Point(12, 56);
            this->linkGithub->Name = L"linkGithub";
            this->linkGithub->Size = System::Drawing::Size(169, 28);
            this->linkGithub->TabIndex = 3;
            this->linkGithub->TabStop = true;
            this->linkGithub->Text = L"Visit us on GitHub";
            this->linkGithub->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::linkGithub_LinkClicked);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(344, 262);
            this->Controls->Add(this->linkGithub);
            this->Controls->Add(this->lblWelcome);
            this->Controls->Add(this->btnClean);
            this->Controls->Add(this->checkedListBox1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"Form1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
            this->Text = L"WinCleaner";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        void checkedListBox1_Click(Object^ sender, EventArgs^ e)
        {
            for (int i = 0; i < checkedListBox1->Items->Count; i++)
            {
                if (checkedListBox1->GetItemRectangle(i).Contains(checkedListBox1->PointToClient(MousePosition)))
                {
                    switch (checkedListBox1->GetItemCheckState(i))
                    {
                    case CheckState::Checked:
                        checkedListBox1->SetItemCheckState(i, CheckState::Unchecked);
                        break;
                    case CheckState::Indeterminate:
                    case CheckState::Unchecked:
                        checkedListBox1->SetItemCheckState(i, CheckState::Checked);
                        break;
                    }
                }
            }
        }


        // Set the fixed size of the form
        void SetFixedSize()
        {
            this->MaximumSize = this->Size;
            this->MinimumSize = this->Size;
        }

        // Set modern UI styling
        void SetModernUI()
        {
            this->Font = gcnew Drawing::Font(L"Segoe UI", 10);
            this->btnClean->FlatStyle = FlatStyle::Flat;
            this->btnClean->FlatAppearance->BorderSize = 0;
            this->btnClean->FlatAppearance->MouseDownBackColor = this->btnClean->BackColor;
            this->btnClean->FlatAppearance->MouseOverBackColor = this->btnClean->BackColor;
            this->lblWelcome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->linkGithub->LinkBehavior = System::Windows::Forms::LinkBehavior::NeverUnderline;
        }

        // Display welcome message
        void DisplayWelcomeMessage()
        {
            String^ username = Environment::UserName;
            lblWelcome->Text = "Welcome, " + username + "!";
        }

        // Open GitHub link in browser
        void OpenGitHubLink()
        {
            System::Diagnostics::Process::Start("https://github.com/aguilarsean/C-CodeGrid");
        }

        // Event handler for Clean button click
        void btnClean_Click(System::Object^ sender, System::EventArgs^ e)
        {
            wchar_t username[UNLEN + 1];
            DWORD username_len = UNLEN + 1;
            GetUserName(username, &username_len);

            std::wstring windowsTempFolder = L"C:\\Windows\\Temp\\";
            std::wstring windowsPrefetchFolder = L"C:\\Windows\\Prefetch\\";
            std::wstring windowsUpdateFolder = L"C:\\Windows\\SoftwareDistribution\\Download\\";
            std::wstring appTempFolder = L"C:\\Users\\" + std::wstring(username) + L"\\AppData\\Local\\Temp\\";
            std::wstring chromeCookiesFolder = L"C:\\Users\\" + std::wstring(username) + L"\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Network\\Cookies";
            std::wstring operagxCookiesFolder = L"C:\\Users\\" + std::wstring(username) + L"\\AppData\Roaming\\Opera Software\\Opera GX Stable\\Network\\Cookies";

            std::vector<int> selectedItems;
            for (int i = 0; i < checkedListBox1->CheckedItems->Count; i++)
            {
                selectedItems.push_back(checkedListBox1->CheckedIndices[i]);
            }

            bool successOperation = false;

            for (int i : selectedItems)
            {
                if (i == 0)
                {
                    CleanFolder(windowsTempFolder);
                    successOperation = true;
                }
                else if (i == 1)
                {
                    CleanFolder(windowsPrefetchFolder);
                    successOperation = true;
                }
                else if (i == 2)
                {
                    CleanFolder(windowsUpdateFolder);
                    successOperation = true;
                }
                else if (i == 3)
                {
                    CleanFolder(appTempFolder);
                    successOperation = true;
                }
                else if (i == 4)
                {
                    String^ cookiesFilePath = gcnew String(chromeCookiesFolder.c_str());
                    try
                    {
                        System::IO::File::Delete(cookiesFilePath);
                        MessageBox::Show("Chrome cookies cleaned successfully!", "Cleanup", MessageBoxButtons::OK, MessageBoxIcon::Information);
                        successOperation = true;
                    }
                    catch (Exception^ ex)
                    {
                        MessageBox::Show("Failed to clean Chrome cookies: " + ex->Message, "Cleanup", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
                else if (i == 5)
                {
                    String^ cookiesFilePath = gcnew String(operagxCookiesFolder.c_str());
                    try
                    {
                        System::IO::File::Delete(cookiesFilePath);
                        MessageBox::Show("Opera GX cookies cleaned successfully!", "Cleanup", MessageBoxButtons::OK, MessageBoxIcon::Information);
                        successOperation = true;
                    }
                    catch (Exception^ ex)
                    {
                        MessageBox::Show("Failed to clean Opera GX cookies: " + ex->Message, "Cleanup", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
            }

            if (successOperation)
            {
                MessageBox::Show("Cleanup completed!", "Cleanup", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else
            {
                MessageBox::Show("Cleanup failed!", "Cleanup", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void CleanFolder(const std::wstring& folderPath)
        {
            std::wstring searchPath = folderPath + L"*.*";
            WIN32_FIND_DATAW findData;
            HANDLE hFind = FindFirstFileW(searchPath.c_str(), &findData);

            if (hFind != INVALID_HANDLE_VALUE)
            {
                do
                {
                    std::wstring filePath = folderPath + findData.cFileName;

                    if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                    {
                        if (!DeleteFileW(filePath.c_str()))
                        {
                            // Handle deletion failure if required
                        }
                    }
                    else
                    {
                        if (wcscmp(findData.cFileName, L".") != 0 && wcscmp(findData.cFileName, L"..") != 0)
                        {
                            std::wstring subFolderPath = folderPath + findData.cFileName + L"\\";
                            CleanFolder(subFolderPath);
                            RemoveDirectoryW(subFolderPath.c_str());
                        }
                    }
                } while (FindNextFileW(hFind, &findData));

                FindClose(hFind);
            }
        }

        // Event handler for GitHub link click
        void linkGithub_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
        {
            OpenGitHubLink();
        }
    };
}
