from django.conf import settings
import smtplib
from email.message import EmailMessage

def send_email(user_code, email):
	msg = EmailMessage()
	msg.set_content(f"Hi! This is your verification code for user {user_code}")
	msg['Subject'] = 'Your verification code for PongGame!'
	email_sender = settings.EMAIL_CODE
	msg['From'] = email_sender
	msg['To'] = email
	password = settings.EMAIL_CODE_PASSWORD

	server = smtplib.SMTP("smtp.gmail.com", 587)
	server.starttls()
	server.login(email_sender, password)
	server.send_message(msg)
	server.quit()