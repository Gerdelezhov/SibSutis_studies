import tkinter as tk
import threading
from pars import sel_parsing, req_parsing, data_search, find_class_names


class MyApp:
    def __init__(self, master):
        find_class_names()
        self.master = master
        self.master.title("ИП-111 Гердележов Д.Д.")
        self.master.geometry("450x250")

        self.button_frame = tk.Frame(self.master)
        self.button_frame.pack()

        self.button1 = tk.Button(
            self.button_frame, text="Request (10 строк)", command=lambda: self.run_in_thread(req_parsing))
        self.button1.pack(side="left", padx=10, pady=10)

        self.button2 = tk.Button(
            self.button_frame, text="Selenium (Вся таблица)", command=lambda: self.run_in_thread(sel_parsing))
        self.button2.pack(side="left", padx=10, pady=10)

        self.entry = tk.Entry(self.master, state="disabled")
        self.entry.pack(pady=10)

        self.search_button = tk.Button(self.master, text="Поиск", state="disabled",
                                       command=lambda: self.run_in_thread(self.search, self.entry.get()))
        self.search_button.pack()

        self.result_text = tk.Text(self.master, height=10, state="disabled")
        self.result_text.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)

    def run_in_thread(self, func, *args):
        if func == req_parsing:
            self.result_text.configure(state="normal")
            self.result_text.insert(1.0, "Подождите...\n")
            self.result_text.configure(state="disabled")
            self.button2.configure(state='disabled')
        elif func == sel_parsing:
            self.result_text.configure(state="normal")
            self.result_text.insert(1.0, "Подождите...\n")
            self.result_text.configure(state="disabled")
            self.button1.configure(state='disabled')

        self.search_button.configure(state='disabled')
        self.entry.configure(state='disabled')

        thread = threading.Thread(target=func, args=args)
        thread.start()

        while thread.is_alive():
            self.master.update()
        else:
            if func == req_parsing:
                self.button2.configure(state='normal')
            elif func == sel_parsing:
                self.button1.configure(state='normal')
            self.enable_entry()

    def search(self, name):
        result = data_search(name)
        out = ''
        for i in result:
            out += str(i) + " "

        self.result_text.configure(state="normal")
        self.result_text.insert(1.0, out + '\n')
        self.result_text.configure(state="disabled")

        self.entry.delete(0, tk.END)

    def enable_entry(self):
        self.entry.configure(state="normal")
        self.search_button.configure(state="normal")


root = tk.Tk()
app = MyApp(root)
root.mainloop()
