import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication
from email.mime.text import MIMEText
import os
import sys


def enviar_correo(file_path, destinatario):

    remitente = "victoraymesada159@gmail.com"
    mail_password = "joqi balt njwg dicg"
    try:
        correo = smtplib.SMTP_SSL('smtp.gmail.com', 465)
        correo.login(remitente, mail_password)
            
        message = MIMEMultipart()
        message['Subject'] = file_path
        message['From'] = remitente
        message['To'] = destinatario

        # Lectura del archivo de texto
        with open(f"{os.getcwd()}/{file_path}", "r") as text_file:
            text_content = text_file.read()

        # Adjuntar el contenido del archivo de texto al mensaje
        attach = MIMEText(text_content)
        message.attach(attach)

        correo.send_message(message)
        print(f"Correo enviado correctamente a {destinatario}")
    except Exception as e:
        print(f"Error al enviar el correo: {str(e)}")
    finally:
        correo.quit()


def enviar_correo_desde_args():
    if len(sys.argv) != 3:
        print("Usage: python Mail.py <file_path> <destinatario>")
        return

    file_path = sys.argv[1]
    destinatario = sys.argv[2]

    enviar_correo(file_path, destinatario)

if __name__ == "__main__":
    enviar_correo_desde_args()