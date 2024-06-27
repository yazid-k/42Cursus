# back/back/pong/forms.py
from django import forms

class RegisterForm(forms.Form):
   username=forms.CharField(max_length=25, required=True)
   email=forms.EmailField(required=True)
   password=forms.CharField(required=True, widget=forms.PasswordInput)

class LoginForm(forms.Form):
   username=forms.CharField(max_length=25, required=True)
   password=forms.CharField(required=True, widget=forms.PasswordInput)

class localMatchForm(forms.Form):
   local_player2_name=forms.CharField(max_length=25, required=True)
