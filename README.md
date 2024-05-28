# Simple Text Editor: the basics of procedural and structural programming
## 🎯 **Purpose of work**
Understand the basics of procedural and structural programming by having hands-on experience
in using these paradigms. Learn how the memory management works inside the process,
understand the virtual memory concept and typical issues with memory allocation and
deallocation, learn the basic data types.

## 📋 **Task**
Develop a console-based text editor that will have the below functionality:
1. Append text symbols to the end
2. Start the new line
3. Use files to loading/saving the information
4. Print the current text to console
5. Insert the text by line and symbol index
6. Search (please note that text can be found more than once)
7. (Optional) Clearing the console <br />
In this case you should clean the console before each command start.

# 📝 **Control questions**
1. What is structural programming paradigm?
   - Структурне програмування - це різновид імперативного програмування, де потік керування(control flow) визначається вкладеними циклами, умовними операторами та підпрограмами, а не через gotos. Змінні, як правило, локальні для блоків (мають лексичний обсяг). </br>
**Він має 3 основні шаблони:** послідовність, вибір і повторення. (sequence, selection, repetition)
   - Вся справа в тому, щоб розбити програму на більш дрібні, більш керовані частини. Це робить код легшим для розуміння, тестування та зміни. Щоб досягти цього, структурне програмування використовує процедури, функції та структури даних.
   - control flow - порядок у якому виконуються складові програми
<br/><br/>
2. What is procedural programming paradigm?
   - Procedural programming is a programming paradigm that revolves around the concept of organizing code into procedures or functions. Each procedure represents a specific task or action that the program needs to perform. The main focus of procedural programming is breaking down a program’s logic into manageable, reusable, and modular components.
   - імперативне програмування з процедурними викликами (procedural calls)
     - **імперативне** - стиль програмування, у якому програма складається з інструкцій, що виконуються послідовно, щоб змінити стан програми. Програміст описує послідовність дій, необхідних для досягнення бажаного результату.
<br/><br/>
3. Which primitive data types do you know? Key differences between them?
   - **Bits**
     - operations on bits - AND/OR/XOR
     - можемо рухати біти за допомогою << та  >> операторів
   - **Void**
     - нічого, пуста множина
     - типове використання: створення(декларування) функції, що нічого не повертає
   - **Boolean**
     - 1 or 0
     - bool зберігається у вигляді 8 bit (1 byte)
     - True or False
     - bool a = false -> a is 000000
     - bool a = true -> a is 0000001
     - 101010 також true
   - **Char**
      - розмір 1 byte (8 bits)
      - зберігаємо символи всередині
      - 255 різних символів можемо зберегти (2^8)
      - in ASCII table
      - UTF-16 зберігаємо 2^16 символів
      - byte b = Ox11 - працюємо як з байтом
   - **Integer**
      - розмір 4 bytes (32 bits) 
      - типи для зберігання цілих значень
      - зазвичай інт зберігає 4 байти, але може бути 8 на деяких платформах
      - також short (2 bytes) and long long (8 bytes)
      - unsigned - беззнаковий (лише позитивні числа)
   - **Floating point**
      - розмір 4 bytes (32 bits)
      - значення для зберігання чисел з комою
      - якщо поставити **s** перед float числом - мінус чи плюс
        <br></br>
6. Which segments does the process memory have?
   - The three primary memory segments are the **stack, the heap, and the code** segment that gets created when a program gets executed all these three memory segments gets created on the RAM.
     <br></br>
   - **Code segment:** The code segment is a portion of memory where the compiled program’s code, including the class definitions and methods, resides. It is typically read-only and is shared among all instances of a program. When the program is loaded into memory, the code segment is loaded as well.
   - **Stack:** The stack is a memory segment used to store temporary data such as local variables and function call information.
     - Стекова пам'ять автоматично керується, і розмір кожного stack frame відомий під час компіляції.
   - **Heap:** The heap is a memory segment used to store dynamically allocated memory, such as objects or instances of classes. When an object is created, memory is allocated on the heap to store its instance variables (object attributes). Each object has its own memory space in the heap, separate from other objects.
        - Пам'яттю купи керують явно, тобто програміст відповідає за розподіл і звільнення пам'яті.
   - **Data** - all the statically allocated data is placed into Data segment of a process.
     - Divided into two parts - the **initialized** data segment and the** uninitialized **data segment
 <br></br>
8. What is the virtual memory space?
   - With virtual addressing, the CPU accesses main memory by generating a virtual address (VA), which is converted to the appropriate physical address before being sent to main memory. The task of converting a virtual address to a physical one is known as address translation. Like exception handling, address translationrequires close cooperation between the CPU hardware and the operating system. Dedicated hardware on the CPU chip called the memory management unit(MMU) translates virtual addresses on the fly, using a lookup table stored in main memory whose contents are managed by the operating system.
<br></br>
10. How to allocate the memory in each segment?
    - **Code:**
      - Розподіл: цей сегмент зазвичай призначений лише для читання та містить скомпільований код програми.
      - Керування: Керується компілятором і завантажувачем. Тут ви не розподіляєте пам’ять безпосередньо.
   - **Stack:**
     
12. How to reallocate the memory in case we don’t have enough space?
13. What is a runtime stack?
   
# 🌟 **Evaluation**
- Appending text to the end 1
- Starting a new line 1
- Saving and loading from file 2
- Printing the current text 1
- Inserting text by line and symbol index 1
- Search algorithm 1
- Correct git usage flow (3+ meaningful
commits) 1
- Theory (test) 1
- Test plan creation and following 1
- (Extra point) Unlimited size of the text
rows and columns 1 <br />
**Total 10 + 1**

# 📚**Links**
PLPP – Programming Languages Principles and Paradigms book <br />
CSAPP – Computer Systems A Programming Perspective book
1. Structural programming: PLPP Chapter 6 (Sequence control commands, structured
programming)
2. Procedural programming: PLPP Chapter 7 (Subprograms)
3. Data types: CSAPP 2.1-2.4
4. Runtime stack: CSAPP 3.7.1
5. Memory management: PLPP Chapter 5
6. Virtual memory: 1.7.3
7. Files: CSAPP 1.7.4
8. File opening/writing/closing API in C: https://cplusplus.com/reference/cstdio/fopen/

# 🧮**Test cases**
[Link on the file with test cases](https://github.com/Viktoriia-Semenko/simple-text-editor-vsemenko/blob/main/text_cases.md)









