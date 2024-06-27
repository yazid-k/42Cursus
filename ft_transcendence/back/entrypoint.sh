#!/bin/bash

# Wait for the database to be ready
until nc -z -v -w30 db 5432
do
  echo "Waiting for database connection..."
  # Wait for 5 seconds before checking again
  sleep 5
done

# Apply migrations
python manage.py makemigrations doubleFapy
python manage.py makemigrations pong
python manage.py migrate

# Start the Django development server
exec python manage.py runserver 0.0.0.0:8000
