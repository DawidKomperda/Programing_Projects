import hashlib
import PySimpleGUI as sg

def main():
    #Login
    login_login_hash = Encoding('Adam')
    #Password
    login_password_hash = Encoding('Leon')
    def HashGeneratorGUI(): #Take input from user and then encode it in live mode
        layout = [
            [sg.Text('Password generation', size=(30, 1), font='Any 13')],
            [sg.Text('Login'), sg.Input(key='-Login-')],
            [sg.Text('HashLogin'), sg.Input('', size=(40, 1), key='hashlogin')],
            [sg.Text('Password'), sg.Input(key='-Password-')],
            [sg.Text('HashPassword'), sg.Input('', size=(40, 1), key='HashPassword')],
        ]
        window = sg.Window('SHA Generator', 
                            layout,
                            auto_size_text=False,
                            default_element_size=(10, 1),
                            text_justification='r',
                            return_keyboard_events=True,
                            grab_anywhere=True)
        #checking if window is still open and taking input from user,
        while True: 
            event, values = window.read()
            if event == sg.WIN_CLOSED:
                break
            login = values["-Login-"]
            password = values['-Password-']
            try:
                #Update corect boxes with encoded from user
                window['HashPassword'].update(Encoding(password)) 
                window['hashlogin'].update(Encoding(login)) 
            except:
                pass
        window.close()

    
    def Password():
        haslo = sg.popup_get_text('Enter Password', password_char='*',)
        if ((haslo and Matches(haslo,login_password_hash)) and (login and Matches(login, login_login_hash))): #Check if Password and Login are the same as encoded data
            print("Successful login")
        else:
            print("Wrong login or password")

        login = sg.popup_get_text(   
            'Enter Login', password_char='*',)

        #login for live demonstration of encoding data
        if (login == 'gui'):       
            HashGeneratorGUI()                              
            return                                         
        
    Password()

#Encoding data
def Encoding(xhash): 
    xutf = xhash.encode('utf-8')
    sha1hashx = hashlib.sha1()
    sha1hashx.update(xutf)
    xhash = sha1hashx.hexdigest()
    return xhash

#Checkin if input is the same as encoded data
def Matches(x, a_hash): 
    xutf = x.encode('utf-8')
    sha1hashx = hashlib.sha1()
    sha1hashx.update(xutf)
    xhash = sha1hashx.hexdigest()
    return xhash == a_hash
    
    

if __name__ == '__main__':
    sg.theme('DarkAmber')
    main()