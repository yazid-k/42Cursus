NAME=inception

NGINX=nginx
MARIADB=mariadb
WORDPRESS=wordpress

IMGDIR=srcs/requirements

$(NAME): $(NGINX) $(MARIADB) $(WORDPRESS)

$(NGINX):
	docker build -t $(NGINX)img $(IMGDIR)/$(NGINX)
	docker run -it --rm -d -p 443:443 --name $(NGINX)container $(NGINX)img

$(MARIADB):
	docker build -t $(MARIADB)img $(IMGDIR)/$(MARIADB)
	docker run -it --rm --name $(MARIADB)container $(MARIADB)img

$(WORDPRESS):
	docker build -t $(WORDPRESS)img $(IMGDIR)/$(WORDPRESS)
	docker run -it --rm --name $(WORDPRESS)container $(WORDPRESS)img
