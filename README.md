Smart Trolley Using RFID (ARM LPC2129 Project)

📌 Project Overview
This project is a **Smart Trolley System using RFID technology** implemented using the **LPC2129 ARM microcontroller**.  
It simulates an automated billing system where items are detected using RFID tags, and the total bill is calculated automatically.

⚙️ Features
- RFID-based item detection
- Automatic addition and removal of item prices
- Real-time display of item totals
- Total bill calculation using switch control
- Interrupt-based event handling (EINT0 & EINT1)

🧠 Working Principle
- Each product (Pen, Pencil) has a unique RFID tag ID.
- When a tag is scanned:
  - The system identifies the item using the tag ID
  - Adds or removes the item price based on mode
- A switch is used to calculate and display the final total bill.

🧩 Hardware Used
- LPC2129 ARM Microcontroller
- RFID Reader Module
- RFID Tags
- LCD Display (16x2)
- Push Buttons / Switches
- Power Supply Unit

💻 Software Used
- Embedded C
- Keil uVision IDE (or similar ARM compiler)
- Flash Magic (for programming LPC microcontroller)

📂 File Description
- `main.c` → Main program logic
- `data_function.h` → Custom functions for LCD, RFID, etc.
- Interrupt routines handle add/remove operations using external interrupts

🔄 Functionality Flow
1. System initializes LCD and RFID module  
2. Displays welcome message  
3. Reads RFID tag input  
4. Adds/removes item price based on mode:
   - Add Mode (EINT0)
   - Remove Mode (EINT1)  
5. Displays item-wise and total cost  
6. Final total shown when switch is pressed  

 🧾 RFID Tag Mapping
| Item    | RFID Tag ID       | Price |
|---------|------------------|-------|
| Pen     | 060067D961D9     | 10    |
| Pencil  | 060067882CC5     | 15    |

 🚀 Future Improvements
- Add more products dynamically
- Integrate barcode scanning
- Wireless billing system (IoT-based)
- Mobile app integration

👨‍💻 Author
- Developed as an ARM Embedded Systems Project
- Smart Trolley using RFID Technology
📌 Note
This project is for educational purposes and demonstrates embedded system design using ARM microcontrollers and RFID technology.
