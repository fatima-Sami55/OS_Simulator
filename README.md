
🖥️ Operating System Simulator
==============================

The **Operating System Simulator** 🧠 is a terminal-based simulation of an OS, developed for the Operating Systems Lab course. It implements core concepts like multitasking, process scheduling, resource management, and user/kernel modes. Interact with tasks like Notepad, Calculator, and Minigames—with optional graphical support 🖼️.

✨ Features
----------

*   **🛠️ Custom OS Branding**: Displays the OS name with a loading animation on boot.
*   **💻 User-Defined Hardware**: Specify RAM, HDD, and CPU cores at startup.
*   **🧵 Multitasking**: Supports multilevel queue scheduling for concurrent tasks.
*   **📋 Task Management**: 15+ tasks, each with minimize/close options.
*   **📦 Resource Management**: Allocates RAM & HDD, terminates if insufficient.
*   **🔐 Kernel/User Modes**: Kernel handles low-level process & hardware operations.
*   **🚨 Interrupt Handling**: Pause/minimize tasks via simulated interrupts.
*   **🧩 Scheduling**: Uses semaphores, mutual exclusion, and condition variables.
*   **💾 Data Storage**: Simulated hard drive stores app data.
*   **🖼️ Graphical Interface (Optional)**: Desktop-like icons for visual interaction.

📋 Requirements
---------------

*   **🖥️ Operating System**: Windows, Linux, or macOS
*   **🧑‍💻 Programming Language**: \[C++\]
*   **📦 Dependencies**:
    *   \[GCC, GCC libraries, SDL, xterm terminal\]
    *   Terminal emulator
*   **🧰 Hardware**:
    *   4GB RAM
    *   1GB free disk space
*   **🔧 Tools**: Git

📥 Installation
---------------

1.  **📂 Clone the Repository**:
    
        git clone https://github.com/fatima-Sami55/OS_Simulator.git
        cd OS_Simulator
    
2.  **📦 Install Dependencies**:
    *   For C/C++:
        
            sudo apt-get install build-essential
        
    *   For Python:
        
            pip install -r requirements.txt
        
3.  **⚙️ Compile (if needed)**:
    
        make
    

▶️ Usage
--------

1.  **🚀 Run the Simulator**:
    
        ./os_simulator
    
    Or for Python:
    
        python main.py
    
2.  **🧠 Boot Process**:
    *   See OS branding + loading animation.
    *   Input hardware specs (RAM, HDD, cores).
3.  **🎮 Interact**:
    *   View the task guide.
    *   Select tasks via number or icon.
    *   Close, minimize, or switch tasks freely.
    *   Use kernel mode for admin operations.
4.  **⏻ Shutdown**:
    *   Select shutdown to terminate all tasks and exit safely.

📑 Available Tasks
------------------

Each task runs as an individual process:

1.  📝 **Notepad**: Auto-save text editor.
2.  🧮 **Calculator**: Basic arithmetic operations.
3.  ⏰ **Clock**: Auto-updating clock.
4.  📆 **Calendar**: Viewable calendar.
5.  📄 **File Creation**: Make files on disk.
6.  📁 **Move File**: Change file locations.
7.  📑 **Copy File**: Duplicate files.
8.  🗑️ **Delete File**: Remove selected files.
9.  🔍 **File Info**: Display file metadata.
10.  💣 **Minesweeper**: CLI-based game.
11.  🎵 **Music Player**: Play system beeps as music.
12.  🖨️ **Print File**: Simulates background printing.
13.  📊 **Task Manager**: Monitor and manage processes.
14.  🖥️ **System Info**: View system specs.
15.  📶 **Download Simulator**: Background download mock.
16.  ✍️ **Text Editor**: Manual-save version of Notepad.

✅ All tasks check system resources before starting.

🤝 Contributing
---------------

1.  Fork the repo.
2.  Create a branch: `git checkout -b feature-branch`
3.  Commit changes: `git commit -m "Add feature"`
4.  Push it: `git push origin feature-branch`
5.  Open a pull request 🧷


📬 Contact
----------

Need help? Open issues on [GitHub](https://github.com/fatima-Sami55/OS_Simulator) 📫

_Good luck exploring the Operating System Simulator! 🚀💡_