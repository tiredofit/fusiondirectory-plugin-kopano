<?php
class kopano extends simplePlugin {
    var $displayHeader = TRUE;
    var $objectclasses = array(
        'kopano-user'
    );
    static function plInfo() {
        return array(
            'plShortName' => _('Kopano') ,
            'plDescription' => _('Kopano Settings') ,
            'plFilter' => '(objectClass=kopano-user)',
            'plIcon' => 'geticon.php?context=applications&icon=kopano&size=48',
            'plSmallIcon' => 'geticon.php?context=applications&icon=kopano&size=16',
            'plSelfModify' => TRUE,
            'plPriority' => 2,
            'plObjectClass' => array(
                'kopano-user'
            ) ,
            'plObjectType' => array(
                'user'
            ) ,
            'plProvidedAcls' => parent::generatePlProvidedAcls(static ::getAttributesInfo())
        );
    }
    static function getAttributesInfo() {
        global $config;
        return array(
            'main' => array(
                'name' => _('Organization') ,
                'attrs' => array(
                    new MailAttribute(_('Email address') , _('Organization Email address') , 'mail', TRUE) ,
                    new BooleanAttribute(_('Active') , _('Give Mail Access') , 'kopanoAccount', FALSE, 0, "", 1, 0) ,
                    new SetAttribute(new MailAttribute(_('Aliases') , _('Aliases') , 'kopanoAliases')) ,
                )
            ) ,
            'Personal' => array(
                'name' => _('Personal Info') ,
                'attrs' => array(
                    new StringAttribute(_('Personal Email Address') , _('Personal Email Address') , 'gosaMailAlternateAddress', FALSE) ,
                    new BooleanAttribute(_('Hide from Address Book') , _('Hide from Address Book') , 'kopanoHidden', FALSE, 0, "", 1, 0) ,
                    new SetAttribute(new SelectAttribute(_('Enabled Features') , _('Give user ability to utilize these features') , 'kopanoEnabledFeatures', FALSE, array(
                        'IMAP',
                        'POP3',
                        'SMTP',
                        'MOBILE',
                        'OUTLOOK'
                    ))) ,
                    new SetAttribute(new SelectAttribute(_('Disabled Features') , _('Deny user ability to utilize these features') , 'kopanoDisabledFeatures', FALSE, array(
                        'IMAP',
                        'POP3',
                        'SMTP',
                        'MOBILE',
                        'OUTLOOK'
                    ))) ,
                )
            ) ,
            'Quotas' => array(
                'name' => _('Quotas') ,
                'attrs' => array(
                    new StringAttribute(_('Send Warning when Mailbox at (MB)') , _('Send Warning email to user at this value') , 'kopanoQuotaWarn', FALSE) ,
                    new StringAttribute(_('Soft Quota (MB)') , _('Limit user from sending email at this value') , 'kopanoQuotaSoft', FALSE) ,
                    new StringAttribute(_('Hard Quota (MB)') , _('Limit user from sending and receiving at this value') , 'kopanoQuotaHard', FALSE) ,
                )
            ) ,
            'Delegation' => array(
                'name' => _('Delegation') ,
                'attrs' => array(
                    new SetAttribute(new MailAttribute(_('Other Users who may directly send as this user') , _('') , 'kopanoSendAsPrivilege')) ,
                )
            ) ,
            'Settings' => array(
                'name' => _('Settings') ,
                'attrs' => array(
                    new BooleanAttribute(_('Administrative Access') , _('Give Administrator Access') , 'kopanoAdmin', FALSE, 0, "", 1, 0) ,
                )
            ) ,
            'Resource Settings' => array(
                'name' => _('Resource Settings') ,
                'attrs' => array(
                    new BooleanAttribute(_('Shared Resource Only') , _('Shared Resource Only') , 'kopanoSharedStoreOnly', FALSE, 0, "", 1, 0) ,
                ) ,
            )
        );
    }
}
?>
