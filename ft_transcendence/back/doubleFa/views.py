from django.shortcuts import render, redirect
from pong.models import UserProfile
from back.send_email import send_email
from .forms import CodeForm
from django.contrib.auth import login
from django.contrib import messages

def verify_view(request):
	form = CodeForm(request.POST or None)
	id = request.session.get('id')
	if id:
		user = UserProfile.objects.get(id=id)
		code_obj = user.code
		code_user = f"{user.username}: {user.code}"
		if not request.POST:
			print(code_user)
			send_email(code_user, user.email)
		if form.is_valid():
			code = form.cleaned_data.get('number')
			if str(code_obj) == code:
				code_obj.save()
				login(request, user)
				messages.success(request, 'You are now logged in!')
				return redirect('home')
	return render(request, 'verify.html', {'form': form})
