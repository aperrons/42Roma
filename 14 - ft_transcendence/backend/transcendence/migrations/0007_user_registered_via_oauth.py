# Generated by Django 4.2.11 on 2024-05-04 00:18

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('transcendence', '0006_remove_user_profile_image'),
    ]

    operations = [
        migrations.AddField(
            model_name='user',
            name='registered_via_oauth',
            field=models.BooleanField(default=False),
        ),
    ]