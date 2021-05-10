<?php

class GroupKopanoAttribute extends MailsAttribute
{
    function getForbiddenValues() {
        $forbidden = array_values($this->getValue());
        $forbidden = array_merge($forbidden, array_values($this->plugin->attributesAccess['gosaMailAlternateAddress']->getValue()));
        $forbidden[] = $this->plugin->attributesAccess['mail']->getValue();
        return $forbidden;
    }
    function getFilterBlackList() {
        return array(
            'mail' => $this->getForbiddenValues()
        );
    }
}

class kopanoGroup extends simplePlugin
{
    var $displayHeader = TRUE;
    var $objectclasses = array(
        'kopano-group'
    );
    /* Return plugin information for acl handling */
    static function plInfo (): array
    {
     return [
            'plShortName' => _('Kopano') ,
            'plDescription' => _('Kopano Group mail options') ,
            'plIcon' => 'geticon.php?context=applications&icon=kopano&size=48',
            'plSmallIcon' => 'geticon.php?context=applications&icon=kopano&size=16',
            'plPriority' => 10,
            'plObjectClass' => ['kopano-user'],
            'plObjectType' => array(
                'group',
                'ogroup-user'
            ) ,
            'plProvidedAcls' => parent::generatePlProvidedAcls(static ::getAttributesInfo())
       ];
    }
    static function getAttributesInfo() {
        return array(
            'main' => array(
                'name' => _('Mail') ,
                'attrs' => array(
                    new MailAttribute(_('Email address') , _('Group Email address') , 'mail', TRUE) ,
                    new BooleanAttribute(_('Active') , _('Give Mail Access') , 'kopanoAccount', FALSE, 0, "", 1, 0) ,
                )
            ) ,
            'Settings' => array(
                'name' => _('Settings') ,
                'attrs' => array(
                    new BooleanAttribute(_('Hide from Address Book') , _('Hide from Address Book') , 'kopanoHidden', FALSE, 0, "", 1, 0) ,
                    new BooleanAttribute(_('Distribution List only') , _('Do not show this group for security permissions inside Kopano') , 'kopanoSecurityGroup', FALSE, 1, "", 0, 1) ,
                )
            ) ,
            'Additional' => array(
                'name' => _('Additional') ,
                'attrs' => array(
                    new SetAttribute(new MailAttribute(_('Aliases') , _('Aliases') , 'kopanoAliases')) ,
                )
            ) ,
            'Delegation' => array(
                'name' => _('Delegation') ,
                'attrs' => array(
                    new UsersAttribute(_('Delegate Access') , _('Other Users who may directly send as this user') , 'kopanoSendAsPrivilege', FALSE) ,
                )
            ) ,
        );
    }
}
?>
