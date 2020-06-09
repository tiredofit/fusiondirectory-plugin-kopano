<?php

class kopanoPluginConfig extends simplePlugin
{
  static function plInfo (): array
  {
    return [
      'plShortName'     => _('Kopano'),
      'plDescription'   => _('Kopano Mail plugin configuration'),
      'plPriority'      => 6,
      'plObjectClass'   => ['fdKopanoPluginConf'],
      'plObjectType'    => ['configuration'],

      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    ];
  }

  static function getAttributesInfo (): array
  {
    return [
      'mail' => [
        'name'  => _('Mail settings'),
        'attrs' => [
        ]
      ],
    ];
  }
}
