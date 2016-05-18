Name:           crda
Version:        1.1.3
Release:        0
License:        ISC
Summary:        Linux central regulatory domain agent
Url:            http://wireless.kernel.org/en/developers/Regulatory/
Group:          System/Base
Source:         http://wireless.kernel.org/download/crda/crda-%{version}.tar.bz2
Source1001: 	crda.manifest
BuildRequires:  gcc
BuildRequires:  libgcrypt-devel
BuildRequires:  libnl2-devel
BuildRequires:  python-M2Crypto
BuildRequires:  wireless-regdb
Requires:       libgcrypt
Requires:       libnl2

%description
This package provides CRDA to be used by the new Linux kernel
wireless subsystem to query from userspace regulatory domains. For
more information see:
http://wireless.kernel.org/en/developers/Regulatory/

%prep
%setup -q
cp %{SOURCE1001} .

%build
make DESTDIR=%{buildroot} UDEV_RULE_DIR=/usr/lib/udev/rules.d SBINDIR=%{_sbindir}

%install
%make_install UDEV_RULE_DIR=/usr/lib/udev/rules.d SBINDIR=%{_sbindir}

%docs_package
%files
%manifest %{name}.manifest
%license LICENSE
%{_sbindir}/crda
%{_sbindir}/regdbdump
%{_prefix}/lib/udev/rules.d/85-regulatory.rules
