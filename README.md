# fusiondirectory-plugin-kopano

# Introduction

This a plugin to manage users/groups/servers for [Kopano](https://www.kopano.io) (fork of Zarafa) within [Fusion Directory](https://wwwfusiondirectory.org) LDAP Manager

[Changelog](CHANGELOG.md)

## Maintainer

- [Dave Conroy](https://github.com/tiredofit)

## Table of Contents

- [Maintainer](#maintainer)
- [Table of Contents](#table-of-contents)
- [Prerequisites and Assumptions](#prerequisites-and-assumptions)
- [Installation](#installation)
- [Screenshots:](#screenshots)
  - [Todo:](#todo)
  - [Known Issues:](#known-issues)
- [Support](#support)
  - [Usage](#usage)
  - [Bugfixes](#bugfixes)
  - [Feature Requests](#feature-requests)
  - [Updates](#updates)
- [License](#license)
- [References](#references)

## Prerequisites and Assumptions

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

### Todo:

* Contacts Management
* Dynamic Groups Management

### Known Issues:

* Delegation for Groups not functioning

## Support

This was built to serve a specific need in a production environment and gradually have had more functionality added based on requests from the community.
### Usage
- The [Discussions board](../../discussions) is a great place for working with the community on tips and tricks of using this.
- Consider [sponsoring me](https://github.com/sponsors/tiredofit) personalized support.
### Bugfixes
- Please, submit a [Bug Report](issues/new) if something isn't working as expected. I'll do my best to issue a fix in short order.

### Feature Requests
- Feel free to submit a feature request, however there is no guarantee that it will be added, or at what timeline.
- Consider [sponsoring me](https://github.com/sponsors/tiredofit) regarding development of features.

### Updates
- Best effort to track upstream changes, More priority if I am actively using this in a production environment.
- Consider [sponsoring me](https://github.com/sponsors/tiredofit) for up to date releases.

## License
MIT. See [LICENSE](LICENSE) for more details.

## References
- [https://www.fusiondirectory.org](https://wwwfusiondirectory.org)
- [https://www.kopano.io](https://www.kopano.io)
- The #fusiondirectory team on freenet
