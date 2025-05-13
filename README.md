Operating System Simulator
==========================

The **Operating System Simulator** is a terminal-based simulation of an operating system, developed for the Operating Systems Lab course. It implements core OS concepts like multitasking, process scheduling, resource management, and user/kernel modes. Users can interact with tasks such as Notepad, Calculator, and Minigames, with optional graphical support.

Features
--------

*   **Custom OS Branding**: Displays the OS name with a loading animation on boot.
*   **User-Defined Hardware**: Specify RAM, hard drive, and CPU cores at startup (e.g., 2GB RAM, 256GB HDD, 8 cores).
*   **Multitasking**: Run multiple tasks concurrently using multilevel queue scheduling.
*   **Task Management**: 15+ tasks, each as a separate process with close/minimize options.
*   **Resource Management**: Allocates RAM and hard drive; terminates tasks if resources are insufficient.
*   **Kernel/User Modes**: Kernel mode manages hardware and processes.
*   **Interrupt Handling**: Pause or minimize tasks via interrupts, moving them to a blocked state.
*   **Scheduling**: Uses mutual exclusion, semaphores, and condition variables.
*   **Data Storage**: Saves data (e.g., Notepad files) to the simulated hard drive.
*   **Graphical Interface** (Optional): Task icons on a desktop-like interface.

Requirements
------------

*   **Operating System**: Windows, Linux, or macOS
*   **Programming Language**: \[e.g., C/C++, Python; specify based on implementation\]
*   **Dependencies**:
    *   \[e.g., GCC for C/C++, Python libraries, or SDL for graphics\]
    *   Terminal emulator
*   **Hardware**:
    *   4GB RAM
    *   1GB free disk space
*   **Tools**: Git

Installation
------------

1.  **Clone the Repository**:
    
        git clone https://github.com/fatima-Sami55/OS_Simulator.git
        cd OS_Simulator
    
2.  **Install Dependencies**:
    *   For C/C++:
        
            sudo apt-get install build-essential
        
    *   For Python:
        
            pip install -r requirements.txt
        
3.  **Compile** (if applicable):
    
        make
    

Usage
-----

1.  **Run the Simulator**:
    
        ./os_simulator
    
    Or, for Python:
    
        python main.py
    
2.  **Boot Process**:
    *   OS name displays with a loading animation.
    *   Input hardware specs (RAM, HDD, cores).
3.  **Interact**:
    *   View the task guide.
    *   Select tasks by number or icon (if graphical).
    *   Close, minimize, or switch tasks.
    *   Use kernel mode for process management.
4.  **Shutdown**:
    *   Select shutdown to close tasks and exit.

Available Tasks
---------------

The simulator includes the following tasks, each running as a separate process:

1.  **Notepad**: Auto-saving text editor.
2.  **Calculator**: Basic arithmetic operations.
3.  **Clock**: Auto-running time display.
4.  **Calendar**: Auto-running calendar view.
5.  **File Creation**: Create files on the hard drive.
6.  **Move File**: Relocate files.
7.  **Copy File**: Duplicate files.
8.  **Delete File**: Remove files.
9.  **File Info**: Show file metadata.
10.  **Minesweeper**: Terminal-based game.
11.  **Music Player**: Background beep sound.
12.  **Print File**: Simulate background printing.
13.  **Task Manager**: Manage processes (kernel mode).
14.  **System Info**: Display OS/hardware details.
15.  **Download Simulator**: Background download task.
16.  **Text Editor**: Manual-save text editing.

Tasks run with resource checks before execution.

Contributing
------------

1.  Fork the repository.
2.  Create a branch: `git checkout -b feature-branch`
3.  Commit changes: `git commit -m "Add feature"`
4.  Push: `git push origin feature-branch`
5.  Open a pull request.


Contact
-------

Open issues on [GitHub](https://github.com/fatima-Sami55/OS_Simulator) for support.
_