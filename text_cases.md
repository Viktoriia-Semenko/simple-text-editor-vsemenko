# Test cases for 'Simple Text Editor'
## Case 1
1. Append text to the end
2. Save text to file
   - The user is asked to write a name for the file to save text ( in format 'file_name.txt' )
   - If file already exists, user is asked whether he wants this file to be overwritten
      - if the answer is 'y', text that was before deletes and new is inserted
      - if the answer is 'n', new text is added to the start of a new line in that file
   - If file with this name not exists, text is appended to the new file
3. Print text
   - This command will print all text that were entered into the console
4. Start a new line
5. Append text to the end
6. Load
   - The user is asked for the name of the file for loading text from
   - Text that is loaded will be displayed in console
7. Print
   - in this test case on the console will be outputed all text that were inputed (not the text from files)

> [!NOTE]  
> After every command the user is asked whether he wants to continue

##### Result of the Case 1
<img width="882" alt="Знімок екрана 2024-05-27 о 00 04 55" src="https://github.com/Viktoriia-Semenko/simple-text-editor-vsemenko/assets/150340301/41ffd059-44a3-4c48-9fa4-b7e2e5d55fc5">


