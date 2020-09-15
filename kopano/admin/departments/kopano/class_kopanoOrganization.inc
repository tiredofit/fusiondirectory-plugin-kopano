<?php
class kopanoOrganization extends simplePlugin
{
	protected $displayHeader = TRUE;
	static function plInfo() : array
	{
		return [
			'plShortName' => _('Kopano'), 'plDescription' => _('Kopano'), 'plObjectClass' => ['kopano-company'], 'plObjectType' => ['organization'], 'plSmallIcon' => 'geticon.php?context=applications&icon=kopano&size=16', 'plProvidedAcls' => parent::generatePlProvidedAcls(static::getAttributesInfo()),
			'plForeignKeys' => ['gosaMailServer' => [['serverGeneric', 'cn'],]]
		];
	}
	static function getAttributesInfo() : array
	{
		global $config;
		return [
			'membership' => [
				'name' => _('Admin'), 'attrs' => [
					new UserAttribute(
						_('System Administrator'),
						_('The user who is the system administrator for this company'),
						'kopanoSystemAdmin',
						FALSE
					),
					new UsersAttribute(
						_('Admin Privileges'),
						_('Users from different companies which are administrator over this company'),
						'kopanoAdminPrivilege',
						FALSE
					),
                //          new SetAttribute(
                //            new ObjectSelectAttribute(
                //              _('View Privileges'), _('Companies with view privileges over selected company'),
                //              'kopanoViewPrivilege', FALSE, ['department'], 'o', 'o', '(objectClass=organization)'
                //            )
                //          ),
					new SelectAttribute(_('Server'), _('Home Server for the public folders for this company'), 'kopanoCompanyServer', FALSE, []),
				]
			], 'Quotas' => [
				'name' => _('Quotas'), 'attrs' => [
					new BooleanAttribute(_('Override Default Quota for Children'), _('Override User default quota for children'), 'kopanoUserDefaultQuotaOverride',	FALSE, 0, "", 1, 0
					), new StringAttribute(
						_('Default Send Warning when Mailbox at (MB)'),
						_('Default user warning email for Quota'),
						'kopanoUserDefaultQuotaWarn',
						FALSE
					), new StringAttribute(_('Default Soft Quota (MB)'), _('Default user Hard Quota'), 'kopanoUserDefaultQuotaSoft', FALSE),
					new StringAttribute(_('Default Hard Quota (MB)'), _('Default user Hard Quota'), 'kopanoUserDefaultQuotaHard', FALSE), new UsersAttribute(
						_('Email when user exceeds their quota'),
						_('Users who will receive a notification email when a user exceeds their quota'),
						'kopanoQuotaUserWarningRecipients',
						FALSE
					), new UsersAttribute(
						_('Email when company exceeds their quota'),
						_('Users who will receive a notification email when this company exceeds its quota'),
						'kopanoQuotaCompanyWarningRecipients',
						FALSE
					),
				]
			],
		];
	}
}
