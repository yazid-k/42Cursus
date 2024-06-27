from django.apps import AppConfig


class DoublefaConfig(AppConfig):
	name = 'doubleFa'
    
	def ready(self):
		import doubleFa.signals
