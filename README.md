# fusiondirectory-plugin-kopano

# Introduction

This a plugin to manage users/groups/servers for [Kopano](https://www.kopano.io] (fork of Zarafa) within [Fusion Directory](https://wwwfusiondirectory.org) LDAP Manager

[Changelog](CHANGELOG.md)

## Authors

- [Dave Conroy](https://github.com/tiredofit)

## Table of Contents

- [Introduction](#introduction)
    - [Changelog](CHANGELOG.md)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#quick-start)
- [Screenshots](#screenshots)
- [Todo](#todo)
- [Known Issues](#known-issues)

## Prerequisites

While this image was built to compliment some of the author's [Docker Images](https://hub.docker.com/r/tiredofit) you can certainly use this plugin in your own install.

To use this we assume the following:

- Functioning [OpenLDAP service](https://github.com/tiredofit/docker-openldap-fusiondirectory) 
- Functioning [Fusion Directory service](https://github.com/tiredofit/docker-fusiondirectory)
- Functioning [Kopano Core Groupware server](https://github.com/tiredofit/docker-kopano)

## Installation

- Install plugin as per other Fusion Directory plugins
- Install .schema to OpenLDAP server. If you have already installed the Kopano schema when installing Kopano, then you can skip this

## Screenshots:

![User Management](/screenshots/user-screenshot.jpg?raw=true "User Management")
![Group Management](/screenshots/group-screenshot.jpg?raw=true "Groups Management")
![Multi Tenant/Organization Management](/screenshots/organization-screenshot.jpg?raw=true "Organization Management")
![Multi Tenant/Systems Management](/screenshots/systems-screenshot.jpg?raw=true "Systems Management")

## Todo:

* Contacts Management
* Dynamic Groups Management

## Known Issues: 

* Delegation for Groups not functioning


### References
- [https://www.fusiondirectory.org](https://wwwfusiondirectory.org)
- [https://www.kopano.io](https://www.kopano.io]
- The #fusiondirectory team on freenet
